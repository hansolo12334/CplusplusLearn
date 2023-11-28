#include "lcd.h"


int lcd::width = 0;
int lcd::height = 0;
unsigned short *lcd::screen_base = NULL;
FT_Library lcd::library = NULL;
FT_Face lcd::face = NULL;


lcd::lcd()
{
    if ((fd = open(FB_DEV, O_RDWR)) < 0)
    {
        perror("open error");
        exit(EXIT_FAILURE);
    }
    //获取屏幕参数信息
    ioctl(fd, FBIOGET_VSCREENINFO, &fb_var);
    ioctl(fd, FBIOGET_FSCREENINFO, &fb_fix);

    screen_size = fb_fix.line_length * fb_var.yres;
    width = fb_var.xres;
    height = fb_var.yres;

    //将显示缓存区映射到进程地址空间
    screen_base = (short unsigned int *)mmap(NULL, screen_size, PROT_WRITE, MAP_SHARED, fd, 0);

    if (MAP_FAILED == (void *)screen_base)
    {
        perror("mmap_error");
        close(fd);
        exit(EXIT_FAILURE);
    }
}

lcd::~lcd()
{
    close(fd);
    if (face!=NULL)
    {
        FT_Done_Face(face);
        FT_Done_FreeType(library);
    }
    munmap(screen_base, screen_size);
    printf("程序结束!\n");
    exit(EXIT_SUCCESS);

}



void lcd::getLcdInfo()
{
    printf("LCD分辨率:%d X %d\n", width, height);
}

void lcd::lcd_draw_line(unsigned int x, unsigned int y, int dir, unsigned int length, unsigned int color)
{
    unsigned short rgb565_color = argb8888_to_rgb565(color);

    unsigned int end;
    unsigned long temp;

    if (x >= width)
    {
        x = width - 1;
    }
    if (y >= height)
    {
        y = height - 1;
    }

    temp = y * width + x;
    if (dir) //水平线
    {
        end = x + length + 1;
        if (end >= width)
        {
            end = width - 1;
        }
        for (; x <= end; x++, temp++)
        {
            screen_base[temp] = rgb565_color;
        }
    }
    else //垂直线
    {
        end = y + length - 1;
        if (end >= height)
        {
            end = height - 1;
        }
        for (; y <= end; y++, temp += width)
        {
            screen_base[temp] = rgb565_color;
        }
    }
}

void lcd::clear_screen()
{
    unsigned short rgb565_black = argb8888_to_rgb565(0x000000);

    unsigned int start_y = 0;
    unsigned int start_x = 0;
    unsigned long temp = start_y * width;

    for (; start_y <= height; start_y++, temp += width)
    {
        for (unsigned int x = start_x; x < width; x++)
        {
            screen_base[temp + x] = rgb565_black;
        }
    }
}


int lcd::freetype_init(const char *font, int angle, unsigned int pixel_width,unsigned int pixel_height)
{
    FT_Error error;
    FT_Vector pen;
    FT_Matrix matrix;
    float rad;
    FT_Init_FreeType(&library);

    error = FT_New_Face(library, FONT_PATH, 0, &face);

    if (error)
    {
        fprintf(stderr, "FT_New_Face error: %d\n", error);
        exit(EXIT_FAILURE);
    }

    /* 原点坐标 */
    pen.x = 0 * 64;
    pen.y = 0 * 64; //原点设置为(0, 0)
    /* 2x2 矩阵初始化 */
    rad = (1.0 * angle / 180) * M_PI; //（角度转换为弧度）M_PI 是圆周率
#if 0                                 //非水平方向
    matrix.xx = (FT_Fixed)( cos(rad) * 0x10000L);
    matrix.xy = (FT_Fixed)(-sin(rad) * 0x10000L);
    matrix.yx = (FT_Fixed)( sin(rad) * 0x10000L);
    matrix.yy = (FT_Fixed)( cos(rad) * 0x10000L);
#endif
#if 1 //斜体 水平方向显示的
    matrix.xx = (FT_Fixed)(cos(rad) * 0x10000L);
    matrix.xy = (FT_Fixed)(sin(rad) * 0x10000L);
    matrix.yx = (FT_Fixed)(0 * 0x10000L);
    matrix.yy = (FT_Fixed)(1 * 0x10000L);
#endif
    /* 设置 */
    FT_Set_Transform(face, &matrix, &pen);
    FT_Set_Pixel_Sizes(face, pixel_width, pixel_height); //设置字体大小 50 0
    return 0;
}

void lcd::lcd_write_charactor(int x, int y, const wchar_t *str, unsigned int color)
{
    unsigned short rgb565_color = argb8888_to_rgb565(color); //得到 RGB565 颜色值
    FT_GlyphSlot slot = face->glyph;
    size_t len = wcslen(str); //计算字符的个数
    long int temp;
    int n;
    int i, j, p, q;
    int max_x, max_y, start_y, start_x;
    // 循环加载各个字符
    for (n = 0; n < len; n++)
    {
        // 加载字形、转换得到位图数据
        if (FT_Load_Char(face, str[n], FT_LOAD_RENDER)){
            continue;
        }

        start_y = y - slot->bitmap_top; //计算字形轮廓上边 y 坐标起点位置 注意是减去 bitmap_top
        if (0 > start_y)
        { //如果为负数 如何处理？？
            q = -start_y;
            temp = 0;
            j = 0;
        }
        else
        { // 正数又该如何处理??
            q = 0;
            temp = width * start_y;
            j = start_y;
        }
        max_y = start_y + slot->bitmap.rows; //计算字形轮廓下边 y 坐标结束位置
        if (max_y > (int)height){
            max_y = height;
        }

        for (; j < max_y; j++, q++, temp += width)
        {
            start_x = x + slot->bitmap_left; //起点位置要加上左边空余部分长度
            if (0 > start_x)
            {
                p = -start_x;
                i = 0;
            }
            else
            {
                p = 0;
                i = start_x;
            }
            max_x = start_x + slot->bitmap.width;
            if (max_x > (int)width){
                max_x = width;
            }

            for (; i < max_x; i++, p++)
            {
                // 如果数据不为 0，则表示需要填充颜色
                if (slot->bitmap.buffer[q * slot->bitmap.width + p]){
                    screen_base[temp + i] = rgb565_color;
                }

            }
        }
        //调整到下一个字形的原点
        x += slot->advance.x / 64; //26.6 固定浮点格式
        y -= slot->advance.y / 64;
    }
}

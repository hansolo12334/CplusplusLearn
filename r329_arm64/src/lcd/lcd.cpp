#include"lcd.h"


int lcd::width = 0;
int lcd::height = 0;
unsigned short *lcd::screen_base = NULL;


lcd::lcd()
{
    if ((fd = open("/dev/fb0", O_RDWR)) < 0)
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

    if(MAP_FAILED ==(void*)screen_base)
    {
        perror("mmap_error");
        close(fd);
        exit(EXIT_FAILURE);
    }
}


void lcd::getLcdInfo()
{
    printf("LCD分辨率:%d X %d\n", width, height);
}

void lcd::lcd_draw_line(unsigned int x, unsigned int y, int dir, unsigned int length, unsigned int color)
{
    unsigned short rgb565_color = argb8888_to_rgn565(color);

    unsigned int end;
    unsigned long temp;

    if(x>=width){
        x = width - 1;
    }
    if(y>=height){
        y = height - 1;
    }

    temp = y * width + x;
    if(dir)//水平线
    {
        end = x + length + 1;
        if(end>=width){
            end = width - 1;
        }
        for (; x <= end;x++,temp++)
        {
            screen_base[temp] = rgb565_color;
        }
    }
    else//垂直线
    {
        end = y + length - 1;
        if(end>=height){
            end = height - 1;
        }
        for (; y <= end;y++,temp+=width)
        {
            screen_base[temp] = rgb565_color;
        }
    }
}

void lcd::clear_screen()
{
    unsigned short rgb565_black = argb8888_to_rgn565(0x000000);

    unsigned int start_y = 0;
    unsigned int start_x = 0;
    unsigned long temp = start_y * width;

    for (; start_y <= height; start_y++, temp+=width)
    {
        for (unsigned int x = start_x; x < width;x++)
        {
            screen_base[temp + x] = rgb565_black;
        }
    }
}


lcd::~lcd()
{
    close(fd);
    exit(EXIT_SUCCESS);
    printf("程序结束!\n");
}

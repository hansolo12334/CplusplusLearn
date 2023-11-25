// /使用 mmap()将显示缓冲区映射到用户空间
// 采用储存映射I/O方式 处理大量屏幕数据


#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<sys/mman.h>
#include<linux/fb.h>
#include<time.h>

#define argb8888_to_rgn565(color) ({\
                unsigned int temp = (color); \
                ( (temp & 0xF80000UL)>>8) |\
                ( (temp & 0xFC00UL)>>5) |\
                ( (temp & 0xF8UL)>>3 );\
                })


static int width; // LCD X分辨率
static int height; // LCD Y分辨率
static unsigned short *screen_base = NULL; //映射后的显存地址



//画点
static void lcd_draw_point(unsigned int x,unsigned int y, unsigned int color)
{
    unsigned short rgb565_color = argb8888_to_rgn565(color);//得到RGB565颜色值


    if(x>=width){
        x = width - 1;
    }
    if(y>=height){
        y = height - 1;
    }

    screen_base[y * width + x] = rgb565_color;
}

//画线 水平垂直
static void lcd_draw_line(unsigned int x, unsigned int y, int dir, unsigned int length, unsigned int color)
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



static void clear_screen()
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

int main()
{
    struct fb_fix_screeninfo fb_fix;
    struct fb_var_screeninfo fb_var;
    unsigned int screen_size;
    int fd;

    if ( (fd=open("/dev/fb0",O_RDWR)) <0 )
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

    useconds_t sleep_time = 0.3 * 1000 * 1000; //0.3秒

    for (int t = 0; t < 10; t++)
    {
        lcd_draw_line(0, t*(height / 10), 1, width, 0xFF);

        usleep(sleep_time);
        clear_screen();
    }


    munmap(screen_base, screen_size);

    close(fd);
    exit(EXIT_SUCCESS);
}

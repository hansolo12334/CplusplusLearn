#ifndef LCD_H
#define LCD_H

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


class lcd
{

public:
    static int width; // LCD X分辨率
    static int height; // LCD Y分辨率
    static unsigned short *screen_base; //映射后的显存地址

    struct fb_fix_screeninfo fb_fix;
    struct fb_var_screeninfo fb_var;
    unsigned int screen_size;
    int fd;

public:
    void getLcdInfo();

    static void lcd_draw_line(unsigned int x, unsigned int y, int dir, unsigned int length, unsigned int color);
    static void clear_screen();


public:
    lcd();
    ~lcd();
};






#endif

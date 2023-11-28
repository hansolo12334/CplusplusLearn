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

#include <errno.h>
#include <wchar.h>
#include<ft2build.h>
#include <math.h> //数学库函数头文件
#include FT_FREETYPE_H

#define argb8888_to_rgb565(color) ({\
                unsigned int temp = (color); \
                ( (temp & 0xF80000UL)>>8) |\
                ( (temp & 0xFC00UL)>>5) |\
                ( (temp & 0xF8UL)>>3 );\
                })


#define FB_DEV "/dev/fb0"  //lcd 设备节点
#define FONT_PATH "/usr/share/fonts/truetype/wqy/wqy-zenhei.ttc"

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
    static FT_Library library;
    static FT_Face face;

public:
    void getLcdInfo();

    static void lcd_draw_line(unsigned int x, unsigned int y, int dir, unsigned int length, unsigned int color);
    static void clear_screen();

    static void lcd_write_charactor(int x, int y,const wchar_t *str,unsigned int color);

    static int freetype_init(const char *font, int angle, unsigned int pixel_width,unsigned int pixel_height);


public:
    lcd();
    ~lcd();
};






#endif

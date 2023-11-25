//对lcd等buffer设备进行应用编程
//应用程序通过对 LCD 设备节点/dev/fb0
//（假设 LCD 对应的设备节点是
// /dev/fb0）进行 I/O 操作即可实现对 LCD 的显示控制，
// 实质就相当于读写了 LCD 的显存，而显存是 LCD 的
// 显示缓冲区，LCD 硬件会从显存中读取数据显示到 LCD 液晶面板上
//在应用程序中，操作/dev/fbX 的一般步骤如下：
// 1.首先打开/dev/fbX 设备文件。
// 2.使用 ioctl()函数获取到当前显示设备的参数信息，譬如屏幕的分辨率大小、像素格式，根据屏幕参
//   数计算显示缓冲区的大小。
// 3.通过存储映射 I/O 方式将屏幕的显示缓冲区映射到用户空间（mmap）
// 4.映射成功后就可以直接读写屏幕的显示缓冲区，进行绘图或图片显示等操作了。
// 5.完成显示后，调用 munmap()取消映射、并调用 close()关闭设备文件。

#ifdef SHOW_INFO
struct fb_var_screeninfo {
 __u32 xres; /* 可视区域，一行有多少个像素点，X 分辨率 */
 __u32 yres; /* 可视区域，一列有多少个像素点，Y 分辨率 */
 __u32 xres_virtual; /* 虚拟区域，一行有多少个像素点 */
 __u32 yres_virtual; /* 虚拟区域，一列有多少个像素点 */
 __u32 xoffset; /* 虚拟到可见屏幕之间的行偏移 */
 __u32 yoffset; /* 虚拟到可见屏幕之间的列偏移 *
__u32 bits_per_pixel; /* 每个像素点使用多少个 bit 来描述，也就是像素深度 bpp */
 __u32 grayscale; /* =0 表示彩色, =1 表示灰度, >1 表示 FOURCC 颜色 */
 /* 用于描述 R、G、B 三种颜色分量分别用多少位来表示以及它们各自的偏移量 */
 struct fb_bitfield red; /* Red 颜色分量色域偏移 */
 struct fb_bitfield green; /* Green 颜色分量色域偏移 */
 struct fb_bitfield blue; /* Blue 颜色分量色域偏移 */
 struct fb_bitfield transp; /* 透明度分量色域偏移 */
 __u32 nonstd; /* nonstd 等于 0，表示标准像素格式；不等于 0 则表示非标准像素格式 */
 __u32 activate;
 __u32 height; /* 用来描述 LCD 屏显示图像的高度（以毫米为单位） */
 __u32 width; /* 用来描述 LCD 屏显示图像的宽度（以毫米为单位） */
 __u32 accel_flags;
 /* 以下这些变量表示时序参数 */
 __u32 pixclock; /* pixel clock in ps (pico seconds) */
 __u32 left_margin; /* time from sync to picture */
 __u32 right_margin; /* time from picture to sync */
 __u32 upper_margin; /* time from sync to picture */
 __u32 lower_margin;
 __u32 hsync_len; /* length of horizontal sync */
 __u32 vsync_len; /* length of vertical sync */
 __u32 sync; /* see FB_SYNC_* */
 __u32 vmode; /* see FB_VMODE_* */
 __u32 rotate; /* angle we rotate counter clockwise */
 __u32 colorspace; /* colorspace for FOURCC-based modes */
 __u32 reserved[4]; /* Reserved for future compatibility */
};

struct fb_bitfield {
 __u32 offset; /* 偏移量 */
 __u32 length; /* 长度 */
 __u32 msb_right; /* != 0 : Most significant bit is right *



struct fb_fix_screeninfo {
 char id[16]; /* 字符串形式的标识符 */
 unsigned long smem_start; /* 显存的起始地址（物理地址） */
 __u32 smem_len; /* 显存的长度 */
 __u32 type;
 __u32 type_aux;
 __u32 visual;
 __u16 xpanstep;
 __u16 ypanstep;
 __u16 ywrapstep;
 __u32 line_length; /* 一行的字节数 */
 unsigned long mmio_start; /* Start of Memory Mapped I/O(physical address) */
 __u32 mmio_len; /* Length of Memory Mapped I/O */
 __u32 accel; /* Indicate to driver which specific chip/card we have */
 __u16 capabilities;
 __u16 reserved[2];
};



#endif



#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<linux/fb.h>

int main(int argc, char* argv[])
{
    //构造两个和 fn.h 中相同的 包含屏幕信息的 结构体 以获取屏幕信息
    struct fb_fix_screeninfo fb_fix;
    struct fb_var_screeninfo fb_var;
    int fd;

    if( (fd=open("/dev/fb0",O_WRONLY)) < 0)
    {
        perror("open error");
        exit(-1);
    }

    //获取屏幕参数
    ioctl(fd, FBIOGET_VSCREENINFO, &fb_var);
    ioctl(fd, FBIOGET_FSCREENINFO, &fb_fix);

    printf("分辨率:%d*%d\n"
            "像素深度bpp:%d\n"
            "一行的字节数:%d\n"
            "像素格式:R<%d %d>G<%d %d>B<%d %d>\n",
            fb_var.xres,fb_var.yres,fb_var.bits_per_pixel,
            fb_fix.line_length,
            fb_var.red.offset,fb_var.red.length,
            fb_var.green.offset,fb_var.green.length,
            fb_var.blue.offset,fb_var.blue.length);
            //分辨率:240*240
            // 像素深度bpp:16
            // 一行的字节数:480
            // 像素格式:R<11 5>G<5 6>B<0 5>


    close(fd);
    exit(0);
}




// 清屏 dd if=/dev/zero of=/dev/fb0 bs=1024 count=112

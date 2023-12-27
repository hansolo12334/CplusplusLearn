#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include<time.h>
#include<pthread.h>

#include "oled.h"
#include "font.h"



#define I2C_PORT "/dev/i2c-2"

static char gpio_path[100];
useconds_t sleep_time = 0.08 * 1000 * 1000; //0.3秒
int value_change = 0;
int last_value=0;

int x = 20;
int y = 10;
int reverse_x = 0;
int reverse_y = 1;

static int gpio_config(const char *attr, const char *val)
{
  char file_path[100];
  int len;
  int fd;


  sprintf(file_path, "%s%s", gpio_path, attr);
  printf("%s\n", file_path);
  if (0 > (fd = open(file_path, O_WRONLY)))
  {
    perror("open error");
    return fd;
  }

  len = strlen(val);
  if (len != write(fd, val, len))
  {
    perror("write error");
    close(fd);
    return -1;
  }
  close(fd); // 关闭文件
  return 0;
}

static void *button_thread_finction(void *privdata)
{
    
  char file_path[100];
  
  char val;
  int fd;
  /* 判断指定编号的 GPIO 是否导出 */
    sprintf(gpio_path, "/sys/class/gpio/gpio%s/", "97");
    
  /* 配置为输入模式 */
  
  printf("%s\n",file_path);
  if (gpio_config("direction", "in"))
    exit(-1);
  /* 极性设置 */
  if (gpio_config("active_low", "0"))
    exit(-1);
  /* 配置为非中断方式 */
  if (gpio_config("edge", "none"))
    exit(-1);
  
 
  /* 读取 GPIO 电平状态 */

  sprintf(file_path, "%s%s", gpio_path, "value");
  printf("%s\n", file_path);

  
  while(1)
  {
    if (0 > (fd = open(file_path, O_RDONLY)))
    {
      perror("open error");
      exit(-1);
    }
    if (0 > read(fd, &val, 1))
    {
      perror("read error");
      close(fd);
      exit(-1);
    }
    
   // printf("value: %c\n", val);
    if(val!=last_value)
    {
      value_change =1;
    }
    else
    {
      value_change = 0;
    }
    last_value = val;
    usleep(sleep_time);
    close(fd);
  }
  
  /* 退出程序 */
  exit(0);
}


int oled_show(struct display_info *disp)
{
  int i;
  char buf[100];

  // disp->font = font1;
  // oled_putstrto(disp, 0, 1, "Welcome to linux ");

  disp->font = font2;
  oled_putstrto(disp, x, y, "hansolo");
  y += 5*reverse_y;
  if(y<=10)
  {
    y = 10;
    reverse_y = 1;
  }
  if(y>=55)
  {
    y = 50;
    reverse_y = -1;
  }
   

  printf("%d %d\n", x, y);

  // disp->font = font3;
  // oled_putstrto(disp, 0, 30, "Welcome to linux ");

  // disp->font = font1;
  // oled_putstrto(disp, 0, 40, "Welcome to linux ");


  oled_send_buffer(disp);

  return 0;
}

void show_error(int err, int add)
{
  // const gchar* errmsg;
  // errmsg = g_strerror(errno);
  printf("\nERROR: %i, %i\n\n", err, add);
  // printf("\nERROR\n");
}

void show_usage(char *progname)
{
  printf("\nUsage:\n%s <I2C bus device node >\n", progname);
}


int main(int argc, char **argv)
{
  int e;
  // char filename[32];
  struct display_info disp;

  // if (argc < 2)
  // {
  //   show_usage(argv[0]);
  //   return -1;
  // }

  memset(&disp, 0, sizeof(disp));
  // sprintf(filename, "%s", argv[1]);
  disp.address = OLED_I2C_ADDR;

  
  e = oled_open(&disp, I2C_PORT);


  pthread_t tid;
  pthread_create(&tid, NULL, button_thread_finction, NULL);


  
  e = oled_init(&disp);

  while(1)
  {
    if(value_change)
    {
      // printf("%d\n", value_change);
      oled_clear(&disp);
      oled_show(&disp);
    }
    
    usleep(sleep_time);
  }
 
  return 0;
}

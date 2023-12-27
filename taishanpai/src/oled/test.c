#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <termios.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include <errno.h>
#include <stdarg.h>
#include <sys/ioctl.h>

#include "oled.h"
#include "wiringPiI2C.h"


int fd;                                 
unsigned char  yi[16]={"Angle of beam:"};
unsigned char  er[16]={"ming"};
unsigned char san[16]={"Distance:"};
unsigned char  si[16]={"okok"};
const unsigned char zi[] = {0x00, 0x7f, 0x08, 0x08, 0x08, 0x7f};
// const unsigned char picture1[];
// const unsigned char picture2[];
// const unsigned char picture3[];
// const unsigned char picture4[];
// const unsigned char picture5[];
// const unsigned char picture6[];
// const unsigned char picture7[];

int init_oled()
{
  fd = wiringPiI2CSetupInterface("/dev/i2c-2", 0x3c);
  printf("%d\n", fd);
  int suc = wiringPiI2CWriteReg8(fd, 0x00, 0xa1);
  suc += wiringPiI2CWriteReg8(fd, 0x00, 0xc8); // L?úí??90xc0
  suc += wiringPiI2CWriteReg8(fd, 0x00, 0x8d); // A?5w?
  suc += wiringPiI2CWriteReg8(fd, 0x00, 0x14);
  suc += wiringPiI2CWriteReg8(fd, 0x00, 0xa6); // óí?>:90xa7
  suc += wiringPiI2CWriteReg8(fd, 0x00, 0xaf); // >:
  return suc == 0 ? 1 : 0;
}

void clear_screen(void) // 清屏
{
  char zt1, zt2;
  for (zt1 = 0; zt1 < 8; zt1++)
  {
    wiringPiI2CWriteReg8(fd, 0x00, 0xb0 + zt1);
    for (zt2 = 0; zt2 < 128; zt2++)
      wiringPiI2CWriteReg8(fd, 0x40, 0x00);
  }
}
static void delay(unsigned int howLong)
{
  struct timespec sleeper, dummy;

  sleeper.tv_sec = (time_t)(howLong / 1000);
  sleeper.tv_nsec = (long)(howLong % 1000) * 1000000;

  nanosleep(&sleeper, &dummy);
}

void ascii(float Angle, float distance) // 字符显示函数
{
  sprintf(er, "%f", Angle);    // float 0 char
  sprintf(si, "%f", distance); // double 0 char
  int zt;
  char zt3, zt4;
  for (zt3 = 0; zt3 < 4; zt3++)
  {
    wiringPiI2CWriteReg8(fd, 0x00, 0xb0 + (zt3 * 2));
    for (zt4 = 0; zt4 < 16; zt4++)
    {
      for (zt = 0; zt < 8; zt++)
      {
        if (zt3 == 0)
          wiringPiI2CWriteReg8(fd, 0x40, zi[yi[zt4] * 16 + zt]);
        else if (zt3 == 1)
          wiringPiI2CWriteReg8(fd, 0x40, zi[er[zt4] * 16 + zt]);
        else if (zt3 == 2)
          wiringPiI2CWriteReg8(fd, 0x40, zi[san[zt4] * 16 + zt]);
        else if (zt3 == 3)
          wiringPiI2CWriteReg8(fd, 0x40, zi[si[zt4] * 16 + zt]);
      }
    }
    wiringPiI2CWriteReg8(fd, 0x00, 0xb0 + (zt3 * 2) + 1);
    for (zt4 = 0; zt4 < 16; zt4++)
    {
      for (zt = 0; zt < 8; zt++)
      {
        if (zt3 == 0)
          wiringPiI2CWriteReg8(fd, 0x40, zi[yi[zt4] * 16 + zt + 8]);
        else if (zt3 == 1)
          wiringPiI2CWriteReg8(fd, 0x40, zi[er[zt4] * 16 + zt + 8]);
        else if (zt3 == 2)
          wiringPiI2CWriteReg8(fd, 0x40, zi[san[zt4] * 16 + zt + 8]);
        else if (zt3 == 3)
          wiringPiI2CWriteReg8(fd, 0x40, zi[si[zt4] * 16 + zt + 8]);
      }
    }
  }
}





int main()
{
  if (!init_oled())
  {
    printf("初始化屏幕失败\n");
    exit(0);
  }
  printf("初始化屏幕成功\n");
  delay(10);

  clear_screen();
  float Angle = 2.98754546;
  float distance = 5.754644545;
  ascii(Angle, distance); // 字符显示

  exit(0);
}
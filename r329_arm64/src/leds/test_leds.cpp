#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


#define LED_GREEN_TRIGGER "/sys/class/leds/green:indicator-2/trigger"
#define LED_RED_TRIGGER   "/sys/class/leds/red:indicator-1/trigger"
#define LED_BLUE_TRIGGER  "/sys/class/leds/blue:indicator-3/trigger"

#define LED_GREEN_BRIGHTNESS "/sys/class/leds/green:indicator-2/brightness"
#define LED_RED_BRIGHTNESS   "/sys/class/leds/red:indicator-1/brightness"
#define LED_BLUE_BRIGHTNESS  "/sys/class/leds/blue:indicator-3/brightness"

#define USAGE() fprintf(stderr,"usage:\n "  \
                            "%s <color-choise>"\
                            " <on|off> "  \
                            " <trigger> "  \
                            " <type>\n"    , argv[0])



bool write_brightness(char *argv[],int fd1,int fd2)
{

    if (!strcmp(argv[2],"on")) //向 trigger 写入 none 亮度写入 1 on
    {
        write(fd1, "none", 4);
        write(fd2, "1", 1);
        printf("%s led state :\nbrightness:  %s\n",argv[1],argv[2]);
    }
    else if (!strcmp(argv[2],"off")) //向 trigger 写入 none 亮度写入 0 off
    {
        write(fd1, "none", 4);
        write(fd2, "0", 1);
        printf("%s led state :\nbrightness: %s\n",argv[1],argv[2]);
    }
    else
    {
        return 0;
    }
    return 1;
}

bool write_trigger(char *argv[],int argc,int fd1)
{
    if(argc!=5)
    {
        return 0;
    }
    if (!strcmp(argv[3],"trigger"))
    {
        printf("trigger: %s\n",argv[4]);
        if (0>write(fd1,argv[4],strlen(argv[4])))
        {
            perror("wirte error!");
        }
    }
    return 1;
}

int getColorChoise(char *color)
{
    if(!strcmp(color,"red"))
    {
        return 1;
    }
    else if(!(strcmp(color,"green")))
    {
        return 2;
    }
    else if(!(strcmp(color,"blue")))
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
int getBrightnessFile(int colorChoise)
{
    switch (colorChoise)
    {
    case 1:
        return open(LED_RED_BRIGHTNESS, O_RDWR);
    case 2:
        return open(LED_GREEN_BRIGHTNESS, O_RDWR);
    case 3:
        return open(LED_BLUE_BRIGHTNESS, O_RDWR);

    default:
        printf("error color");
        exit(-1);
    }
}


int getTriggerFile(int colorChoise)
{
    switch (colorChoise)
    {
    case 1:
        return open(LED_RED_TRIGGER, O_RDWR);
    case 2:
        return open(LED_GREEN_TRIGGER, O_RDWR);
    case 3:
        return open(LED_BLUE_TRIGGER, O_RDWR);

    default:
        printf("error color");
        exit(-1);
    }
}





int main(int argc,char *argv[])
{
    int fd1, fd2;

    if(2>argc){
        USAGE();
        exit(-1);
    }

    /*打开文件*/
    int colorChoise;
    colorChoise = getColorChoise(argv[1]);
    if (!colorChoise)
    {
        USAGE();
        exit(-1);
    }


    fd1 = getTriggerFile(colorChoise);
    if (0 > fd1)
    {
        perror("open LED_TRIGGER FILE error");
        exit(-1);
    }
    fd2 = getBrightnessFile(colorChoise);
    if (0 > fd2)
    {
        perror("open LED_BRIGHTNESS FILE error");
        exit(-1);
    }


    //颜色正确 进入亮度和trigger
    if(!write_brightness(argv,fd1,fd2))
    {
        USAGE();
        exit(-1);
    }
    if(!write_trigger(argv,argc,fd1))
    {
        if (argc!=3)
        {
            USAGE();
        }
        exit(-1);
    }
    exit(0);
}

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


#define LED_TRIGGER "/sys/class/leds/green:indicator-2/trigger"
#define LED_BRIGHTNESS "/sys/class/leds/green:indicator-2/brightness"
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


int main(int argc,char *argv[])
{
    int fd1, fd2;

    if(2>argc){
        USAGE();
        exit(-1);
    }

    /*打开文件*/
    fd1 = open(LED_TRIGGER, O_RDWR);
    if(0>fd1){
        perror("open LED_TRIGGER FILE error");
        exit(-1);
    }
    fd2 = open(LED_BRIGHTNESS, O_RDWR);
    if(0>fd2){
        perror("open LED_BRIGHTNESS FILE error");
        exit(-1);
    }

                //字符串相同为0
    if ( !strcmp(argv[1], "red") && !strcmp(argv[1],"green") && !strcmp(argv[1],"blue") )
    {
        USAGE();
        exit(-1);
    }
    //颜色正确 进入亮度和trigger
    else
    {
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
    }
    exit(0);
}

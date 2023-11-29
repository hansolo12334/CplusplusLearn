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

#include<linux/input.h>

#include<pthread.h>

/* 按键按下为1 松开为0  */
/* 4个按钮*/
/*左前 105 左后 30*/
/*右前 106 右后 48*/

static int button_fd=-1;
static struct input_event event[2];

static void *button_thread_function(void *privdata) //privdata 线程参数 传递任何数据
{
    while(read(button_fd, &event, 2*sizeof(struct input_event)) > 0)
        {

        if(event[0].code==105)
        {
            printf("左前");
        }
        else if (event[0].code==106)
        {
            printf("右前");
        }
        else if (event[0].code==30)
        {
            printf("左后");
        }
        else if (event[0].code==48)
        {
            printf("右后");
        }

        if (event[0].value==1)
        {
            printf("按键按下\n");
        }
        if (event[0].value==0)
        {
            printf("按键松开\n");
        }


        printf("%d , %d, %d\n" , event[0].type, event[0].code, event[0].value);

    }
}
int main()
{

    printf("%d\n",button_fd);
    button_fd = open("/dev/input/event0", O_RDONLY);


    pthread_t tid;

    pthread_create(&tid, NULL, button_thread_function, NULL);

    while(1)
    {

    }
    exit(0);
}

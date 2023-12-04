#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

#include<time.h>



static void* new_thread_start(void *arg)
{
    printf("新线程： 进程 ID <%d>  线程ID<%lu>\n", getpid(), pthread_self());
    while (1)
    {
        sleep(1);
        printf("2\n");
    }

    // return (void *)0;
    pthread_exit(NULL);
}


int main()
{
    pthread_t tid;
    int ret;

    ret = pthread_create(&tid, NULL, new_thread_start, NULL);

    if (ret)
    {
        fprintf(stderr, "error：%s\n", strerror(ret));
        exit(01);
    }


    printf("主线程： 进程 ID <%d>  线程ID<%lu>\n", getpid(), pthread_self());

    int i = 0;
    while (1)
    {
        i++;
        sleep(1);
        printf("1\n");
        if(i>5)
        {
            printf("主线程结束\n");
            pthread_exit(NULL);//线程结束 可在任意线程调用 主线程结束 子线程仍在进行
        }
    }


    exit(0);
}

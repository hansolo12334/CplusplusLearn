#include<pthread.h>

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>

//线程清理函数 ？ 当线程结束时，才会调用这些函数 做一下处理

static void cleanup(void *arg)
{
    printf("clean up %s\n", (char *)arg);
}


static void* new_thread_start(void *args)
{
    printf("新线程启动\n");
    pthread_cleanup_push(cleanup, "第1次调用");
    pthread_cleanup_push(cleanup, "第2次调用");
    pthread_cleanup_push(cleanup, "第3次调用"); //是一个线程清理函数栈 先进去的最后处理

    sleep(2);

    pthread_exit((void *)0);
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
}
//  输出结果：
/*
    新线程启动
    clean up 第3次调用
    clean up 第2次调用
    clean up 第1次调用
    新线程终止, code=0
*/

int main()
{
    pthread_t tid;
    int ret;
    ret = pthread_create(&tid, NULL, new_thread_start, NULL);
    if(ret){
        fprintf(stderr, "pthread_create error%s\n", strerror(ret));
        exit(-1);
    }

    void *tred;
    ret = pthread_join(tid, &tred);
    if(ret){
        fprintf(stderr, "pthread_join error%s\n", strerror(ret));
        exit(-1);
    }


    printf("新线程终止, code=%ld\n", (long)tred);
    exit(0);
}

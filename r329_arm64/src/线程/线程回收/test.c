#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

#include<time.h>


static void* new_thread_start(void *arg)
{
    int t = *(int *)arg;
    printf("新线程将在%d秒后结束\n", t);
    while (t > 0)
    {
        sleep(1);
        printf("%d\n", t);
        t--;
    }
    pthread_exit((void *)10);
}


int main()
{
    pthread_t tid;
    void *tret;
    int ret;

    int times = 5;
    ret = pthread_create(&tid, NULL, new_thread_start, &times);
    if (ret)
    {
        fprintf(stderr, "error：%s\n", strerror(ret));
        exit(-1);
    }

    ret = pthread_join(tid, &tret);
    //主线程调用 pthread_create()创建新线程之后，新线程执行 new_thread_start()函数，而在主线程中调用
    //pthread_join()阻塞等待新线程终止，新线程终止后，pthread_join()返回，将目标线程的退出码保存在*tret 所
    //指向的内存中
    if (ret)
    {
        fprintf(stderr, "error：%s\n", strerror(ret));
        exit(-1);
    }
    printf("新线程终止 code=%ld\n", (long)tret);

    exit(0);
}

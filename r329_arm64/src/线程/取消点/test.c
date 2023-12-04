#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

#include<time.h>

//遇到取消点 线程会立刻取消 比如 有 sleep printf

static void* new_thread_start(void *arg)
{


    //pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    //printf("该线程设置不可取消!\n");
    int t = *(int *)arg;
    printf("新线程1将在%d秒后结束\n", t);

    sleep(1);
    printf("%d\n", t); //把 printf 和 sleep移除循环试试

    while (t)
    {

        pthread_testcancel();
    }
    pthread_exit((void *)10);
}

static void* new_thread_start1(void *arg)
{
    int t = 20;
    printf("新线程2将在%d秒后结束\n", t);
    while (t > 0)
    {
        sleep(1);
        printf("%d\n", t);
        t--;
        if(t==15)
        {
            pthread_t tid = *(pthread_t *)arg;
            int ret = pthread_cancel(tid);
            if (ret)
            {
                fprintf(stderr, "error：%s\n", strerror(ret));
                exit(-1);
            }
            printf("在子线程2中取消子线程1！\n");
        }
    }
    pthread_exit((void *)11);

}

int main()
{
    pthread_t tid;
    void *tret;
    void *tret1;
    int ret;

    int times = 15;
    ret = pthread_create(&tid, NULL, new_thread_start, &times);
    if (ret)
    {
        fprintf(stderr, "error：%s\n", strerror(ret));
        exit(-1);
    }

    pthread_t tid1;
    ret = pthread_create(&tid1, NULL, new_thread_start1, &tid);
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
    ret = pthread_join(tid1, &tret1);
    if (ret)
    {
        fprintf(stderr, "error：%s\n", strerror(ret));
        exit(-1);
    }
    printf("新线程终止1 code=%ld\n", (long)tret);
    printf("新线程终止2 code=%ld\n", (long)tret1);
    exit(0);
}

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>


static void *new_thread_start(void *args)
{
    int ret;
    ret = pthread_detach(pthread_self());
    if(ret)
    {
        fprintf(stderr, "pthread_detach error %s\n", strerror(ret));
        return NULL;
    }
    printf("新线程 start\n");
    sleep(2);
    printf("新线程 end\n");
    pthread_exit((void *)10);
}


int main()
{
    pthread_t tid;

    int ret;

    ret = pthread_create(&tid, NULL, new_thread_start, NULL);

    if(ret){
        fprintf(stderr, "pthread_create error %s\n", strerror(ret));
        exit(-1);
    }

    sleep(1);

    void *tret;
    ret = pthread_join(tid, &tret);
    if(ret){
        fprintf(stderr, "pthread_join error %s\n", strerror(ret));
    }
    printf("新线程终止 code=%ld\n", (long)tret);
    pthread_exit(NULL);
}

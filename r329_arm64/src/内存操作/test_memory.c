#include<stdio.h>
#include<stdlib.h>


/// @brief 测试分配内存的操作  设置一个结构体 命令行输入存入的数据
typedef struct hansolo
{
    int x;
    int y;
} stc;

int main(int argc,char *argv[])
{
    stc *new_stc = NULL;

    if ((argc-1)%2!=0)
    {
        printf("输入成对数据!\n");
        exit(0);
    }


    new_stc = (stc *)calloc( (argc - 1)/2, sizeof(stc));

    if(new_stc==NULL)
    {
        printf("calloc error\n");
        exit(-1);
    }

    for (int j = 0; j < (argc - 1) / 2;j++)
    {
        for (int i = 1; i < argc ; i = i + 2)
        {
            new_stc[j].x = atoi(argv[i]);
            new_stc[j].y = atoi(argv[i + 1]);
        }
    }

    for (int j = 0; j < (argc - 1) / 2;j++)
    {

        printf("x: %d y: %d\n", new_stc[j].x, new_stc[j].y);

    }
    putchar('\n');
    exit(0);
}

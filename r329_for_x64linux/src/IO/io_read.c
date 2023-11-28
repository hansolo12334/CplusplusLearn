#include <stdio.h>
#include <stdlib.h>

#define MAX_READBITS 15


int main(void)
{
    char buf[50]={0};
    FILE *fp=NULL;

    int size;

    if( ( fp = fopen("/home/hansolo/CplusplusLearn/r329_for_x64linux/src/IO/test_file.txt","r") )==NULL ){
        perror("fopen error\n");
        exit(-1);
    }

    if( (size = fread(buf,1,MAX_READBITS,fp))< MAX_READBITS ){
        if(ferror(fp))
        {
            printf("fread error\n");
            fclose(fp);
            exit(-1);
        }

    }

    printf("成功读取%d个字节的数据: %s\n", size, buf);
    fclose(fp);
    exit(0);
}

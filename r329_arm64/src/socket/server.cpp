#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<ctype.h>

#define MAXLINE 80
#define SERV_PORT 2223
// #define SERVER_IP "192.168.39.197"
#define SERVER_IP "127.0.0.1"


int main(void)
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd==-1)
    {
        printf("Socket error\n");
        exit(0);
    }


    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //servaddr.sin_addr.s_addr = inet_addr("0.0.0.0");
    servaddr.sin_port = htons(SERV_PORT);

    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr))==-1)
    {
        printf("bind error\n");
        close(listenfd);
        exit(0);
    }

    listen(listenfd, 20);

    printf("Accepting connections ...\n");
    while (1) {
        cliaddr_len = sizeof(cliaddr);
        connfd = accept(listenfd,
                (struct sockaddr *)&cliaddr, &cliaddr_len);

        if (connfd==-1)
        {
            printf("accept error\n");
            exit(0);
        }


        n = read(connfd, buf, MAXLINE);
        printf("received from %s at PORT %d\n",
               inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
               ntohs(cliaddr.sin_port));

        for (i = 0; i < n; i++){
            buf[i] = toupper(buf[i]);
        }
        write(connfd, buf, n);
        close(connfd);
    }
}

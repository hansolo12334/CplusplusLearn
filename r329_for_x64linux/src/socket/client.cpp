#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 80
#define SERV_PORT 2223
// #define SERVER_IP "192.168.39.197"
#define SERVER_IP "192.168.79.101"
// #define SERVER_IP "127.0.0.1"

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;
    char *str;

    char *server_ip;

    if (argc != 3)
    {
        fputs("usage: ./client server_ip message  \n ", stderr);
        exit(1);
    }
    str = argv[2];

    server_ip = argv[1];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = inet_addr(server_ip);

    inet_pton(AF_INET, server_ip, &servaddr.sin_addr);


    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));




    write(sockfd, str, strlen(str));

    n = read(sockfd, buf, MAXLINE);
    printf("Response from server:\n");
    write(STDOUT_FILENO, buf, n);
    printf("\n");

    close(sockfd);
    return 0;
}

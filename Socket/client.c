#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<linux/in.h>

struct sockaddr_in saddr;
struct sockaddr_in caddr;
int sfd,cfd;
int len;
unsigned char buff[1024];

int main(int argc, char const *argv[])
{
    cfd = socket(AF_INET, SOCK_STREAM, 0);

    saddr.sin_family = AF_INET; 
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    saddr.sin_port = htons(5678); 

    connect(cfd,(struct sockadrr *)&saddr, sizeof(struct sockaddr_in));
    read(cfd, buff,1024);
    printf("Server Sent: %s\n",buff);
    

    write(cfd, "Hello Yashwant\n", 15);
    

    close(cfd);
    return 0;
}
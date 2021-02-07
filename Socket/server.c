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
    sfd = socket(AF_INET, SOCK_STREAM, 0);

    saddr.sin_family = AF_INET; 
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    saddr.sin_port = htons(5678); 

    bind(sfd,(struct sockadrr *)&saddr, sizeof(struct sockaddr_in));
    listen(sfd,10);

    len = sizeof(struct sockaddr_in);
    cfd = accept(sfd,(struct sockaddr *)&caddr, &len);

    write(cfd, "Hello Kamal\n", 12);
    read(cfd, buff,1024);
    printf("client Sent: %s\n",buff);

    close(sfd);
    close(cfd);
    return 0;
}

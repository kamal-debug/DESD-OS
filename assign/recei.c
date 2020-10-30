#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int rbuff[128],integ[128];
    int fd;
    mkfifo("desd",S_IRUSR | S_IWUSR);
    fd = open("desd",O_RDONLY);
    read(fd,rbuff,128);
    printf("1st integer:%d\n",rbuff[0]);
    printf("2nd integ:%d\n",rbuff[1]);
    close (fd);
    
    return 0;
}
int add(int a,int b)
{
    return a+b;
}
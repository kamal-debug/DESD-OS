#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>




int main(int argc, char const *argv[])
{
    int fd,integ[128];

    printf("enter two integer:\n");
    scanf("%d%d",&integ[0],integ[1]);

    mkfifo("desd",S_IRUSR | S_IWUSR);
    fd = open("desd",O_WRONLY);
    write(fd,integ,128);
    printf("1st integer:%d\n",integ[0]);
    printf("2nd integer:%d\n",integ[1]);
    close (fd);
    
    return 0;
}

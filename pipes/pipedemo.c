#include<stdio.h>
#include <fcntl.h>              
#include <unistd.h>

int main(int argc, char const *argv[])
{
    unsigned char rbuff[128];
    int pfd[2];
    pipe(pfd);
    pid_t id;

    id = fork();
    if(id==0)//child
    {
        read(pfd[0],rbuff,128);
        printf("Read string from Parent:%s",rbuff);
        close (pfd[0]);

    }
    else//parent
    {
        write(pfd[1],"cdachyd\n",8);
        close (pfd[1]);


    }


    return 0;
}


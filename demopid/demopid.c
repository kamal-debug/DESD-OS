#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{

    pid_t pid;
    pid_t ppid;

    pid = getpid();
    ppid = getppid();

    printf("PID:%d\n",pid);
    printf("PPID:%d\n",ppid);


    
    return 0;
}

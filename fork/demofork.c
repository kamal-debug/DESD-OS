#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{

    pid_t id;
    printf("Before fork\n");
    id = fork();
    printf("after Fork id:%d pid:%d ppid:%d\n",id,getpid(),getppid());
    
    return 0;
}

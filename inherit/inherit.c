#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;

    id = fork();

    if(id==0){

        printf("Child Starting:\n");
        sleep(12);
        printf("child exiting\n");
    }
    else
    {
        printf("parent Starting:\n");
        sleep(2);
        printf("Parent exiting\n");
    }
    
    
    return 0;
}

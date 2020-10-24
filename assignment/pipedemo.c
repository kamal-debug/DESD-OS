#include<stdio.h>
#include <fcntl.h>              
#include <unistd.h>

int main(int argc, char const *argv[])
{

    int pfd[2],pfd1[2],integ[128],rbuff[128];
    pipe(pfd);
    pipe(pfd1);
    pid_t id;
     
    printf("Enter two numbers:\n");
    scanf("%d %d",&integ[0],&integ[1]);

    

    id = fork();
    if(id==0)//child
    {
        printf("****************\n");
        printf("You Are In 2nd Process->\n");
        read(pfd[0],integ,128);
        printf("Process2 Received 1st num: %d\n",integ[0]);
        printf("Process2 Received 2nd num: %d\n",integ[1]);
        rbuff[0]= add(integ[0],integ[1]);
        write(pfd1[1],rbuff,128);
        printf("Process2 send sum to Process1: %d\n",rbuff[0]);
        close(pfd1[1]);        

    }
    else//parent
    {
        printf("*****************\n");
        printf("You are in 1st Process->\n");
        write(pfd[1],integ,128);
        printf("Process1 sent 1st num to Process2: %d\n",integ[0]);
        printf("Process1 sent 2nd num to Process2: %d\n",integ[1]);
        close (pfd[1]);
        read(pfd1[0],rbuff,128);
        printf("*****************\n");
        printf("You are in 1st Process Again:\n");
        printf("Process1 Recieved Sum from Process2: %d\n",rbuff[0]);



    }


    return 0;
}
int add(int a,int b)
{
    return a+b;
}


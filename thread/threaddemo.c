#include<stdio.h>
#include<pthread.h>
#include <unistd.h>


void *thread(void *arg)
{
    printf("New Thread\n");
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    printf("before thread Creation\n");
    pthread_create(&tid,NULL,thread,NULL);
    //sleep(1);
    return 0;
}

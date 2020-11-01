#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
pthread_mutex_t count_mutex;
int count =0;
void *inc_thread(void *arg)
{
    while(1){
        pthread_mutex_lock(&count_mutex);
        count++;
        printf("inc Thread:%d\n",count);
        pthread_mutex_unlock(&count_mutex);
    }
}
void *dec_thread(void *arg)
{
    while(1){
        pthread_mutex_lock(&count_mutex);
        count--;
        printf("dec Thread:%d\n",count);
        pthread_mutex_unlock(&count_mutex);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t tid_inc, tid_dec;
    pthread_mutex_init(&count_mutex,NULL);// Inazalise The Mutex

    pthread_create(&tid_inc,NULL,inc_thread,NULL);
    pthread_create(&tid_dec,NULL,dec_thread,NULL);
    
    pthread_join(tid_inc,NULL);
    pthread_join(tid_dec,NULL);

    pthread_mutex_destroy(&count_mutex);// Destroy the mutex
    return 0;
}

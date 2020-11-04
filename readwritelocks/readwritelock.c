#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int count =0;
pthread_rwlock_t count_lock;


void *thread1(void *data){
    pthread_rwlock_wrlock(&count_lock);
    count++;
    pthread_rwlock_unlock(&count_lock);
}

void *thread2(void *data){
    printf("T2:Getting Inside In Critical Section\n");
    pthread_rwlock_rdlock(&count_lock);
    sleep(1);
    printf("T2 count:%d\n",count);
    pthread_rwlock_unlock(&count_lock);
    printf("T2:Getting out of Critical Section\n");

}

void *thread3(void *data){
    printf("T3:Getting Inside In Critical Section\n");
    pthread_rwlock_rdlock(&count_lock);
    printf("T3 Count:%d\n",count);
    pthread_rwlock_unlock(&count_lock);
    printf("T3:Getting out of Critical Section\n");
}

void *thread4(void *data){
    printf("T4:Getting Inside In Critical Section\n");

    pthread_rwlock_rdlock(&count_lock);
    printf("T4 Count:%d\n",count);
    pthread_rwlock_unlock(&count_lock);
    printf("T4:Getting out of Critical Section\n");
}
int main(int argc, char const *argv[])
{
    pthread_t tid1, tid2,tid3,tid4;

    pthread_rwlock_init(&count_lock,NULL);

    pthread_create(&tid1,NULL,thread1,NULL);
    pthread_create(&tid2,NULL,thread2,NULL);
    pthread_create(&tid3,NULL,thread3,NULL);
    pthread_create(&tid4,NULL,thread4,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);

    pthread_rwlock_destroy(&count_lock);

    return 0;
}

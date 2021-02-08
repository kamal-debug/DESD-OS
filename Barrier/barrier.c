#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_barrier_t barr;


void* serial(void* arg)
{
    printf("Serial:Initilization Started\n");
    sleep(2);
    printf("Serial:Initialized\n");
    pthread_barrier_wait(&barr);
    printf("Serial: Started\n");


}
void* lcd(void* arg)
{
    printf("LCD:Initilization Started\n");
    sleep(10);
    printf("LCD:Initialized\n");
    pthread_barrier_wait(&barr);
    printf("LCD: Started\n");
}
void* ethernet(void* arg)
{
    printf("ETHERNET:Initilization Started\n");
    sleep(5);
    printf("ETHERNET:Initialized\n");
    pthread_barrier_wait(&barr);
    printf("Ethernet:Started\n");
    
}
void* adc(void* arg)
{
    printf("ADC:Initilization Started\n");
    sleep(8);
    printf("ADC:Initilialized\n");
    pthread_barrier_wait(&barr);
    printf("ADC: Started\n");
    
}

int main(int argc, char const *argv[])
{
    pthread_t s,l,e,a;
    pthread_barrier_init(&barr,NULL,4);

    pthread_create(&s,NULL,serial,NULL);
    pthread_create(&l,NULL,lcd,NULL);
    pthread_create(&e,NULL,ethernet,NULL);
    pthread_create(&a,NULL,adc,NULL);
    
    pthread_join(s,NULL);
    pthread_join(l,NULL);
    pthread_join(e,NULL);
    pthread_join(a,NULL);

    pthread_barrier_destroy(&barr);
    return 0;
}

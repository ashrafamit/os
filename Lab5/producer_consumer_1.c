#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* producer(void* arg)
{
    int* v= (int*)arg;
    printf("Hi! this is producer");
    printf("\nPass %d",*v);
}

int main()
{
    pthread_t t1;
    int value=5;
    pthread_create(&t1,NULL,&producer,&value);

    pthread_join(t1,NULL);

    return 0;
}
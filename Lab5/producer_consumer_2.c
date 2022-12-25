#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* producer(void* arg)
{
    int* v= (int*)malloc(sizeof(int));
    *v=9;

    // return v;
}

int main()
{
    pthread_t t1;
    int value=5;
    int* res;
    pthread_create(&t1,NULL,&producer,&value);

    pthread_join(t1,(void*)&res);

    printf("%d",*res);

    return 0;
}
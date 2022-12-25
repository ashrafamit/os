#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

int a[10];
int count=0;

pthread_mutex_t m;

void* producer()
{
    for (int i = 0; i < 100; i++)
    {
        if(count<10)
        {
            pthread_mutex_lock(&m);
            a[count]=rand()%100;
            printf("\nproduced item is %d",a[count] );
            count++;
            pthread_mutex_unlock(&m);
        }
        else
        {
            sleep(1);
        }
        
    }
    
    
}
void* consumer()
{
    int y;
    while(1)
    {
        if(count>=0)
        {
            pthread_mutex_lock(&m);
            
            count--;
            y=a[count];
            printf("\nconsumed item is %d",a[count] );

            pthread_mutex_unlock(&m);
            
        }
        else
        {
            sleep(2);
        }
    }
    
}

int main()
{
    pthread_t t1,t2;

    // for (int i = 0; i < 10; i++)
    // {
    //     pthread_create(&t1[i],NULL,&producer,NULL);
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     pthread_join(t1[i],NULL);
    // }
    

    pthread_mutex_init(&m,NULL);
    pthread_create(&t1,NULL,&producer,NULL);
    pthread_create(&t2,NULL,&consumer,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_mutex_destroy(&m);

    return 0;
}


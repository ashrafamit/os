#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define np 5
// np: number of philosopher
sem_t chopstick[np];

void *philos(void *n)
{
    int ph = *(int *)n;

    //want to eat
    printf("Philosopher %d wants to eat\n", ph+1);

    //pick left chopstick
    printf("Philosopher %d tries to pick left chopstick\n", ph+1);
    sem_wait(&chopstick[ph]);
    printf("Philosopher %d picks the left chopstick\n", ph+1);

    //pick right chopstick
    printf("Philosopher %d tries to pick the right chopstick\n", ph+1);
    sem_wait(&chopstick[(ph + 1) % np]);
    printf("Philosopher %d picks the right chopstick\n", ph+1);

    //start eating
    printf("Philosopher %d begins to eat\n", ph+1);
    //go to sleep, other thread to request and wait
    sleep(2);

    //finish eating, leave chopsticks
    printf("Philosopher %d has finished eating\n", ph+1);
    sem_post(&chopstick[(ph + 1) % np]);
    printf("Philosopher %d leaves the right chopstick\n", ph+1);
    sem_post(&chopstick[ph]);
    printf("Philosopher %d leaves the left chopstick\n", ph+1);
}


int main()
{
    int i, n[np];
    pthread_t T[np];

    for (i = 0; i < np; i++)
    {
        sem_init(&chopstick[i], 0, 1);  //share with threads and one chopstick
    }


    for (i = 0; i < np; i++)
    {
        n[i] = i;
        pthread_create(&T[i], NULL, philos, (void *)&n[i]);
    }
    for (i = 0; i < 5; i++)
    {
        pthread_join(T[i], NULL);
    }


    for (i = 0; i < np; i++)
    {
        // sem_destroy(&chopstick[i]); 
    }
}

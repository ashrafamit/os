#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define BufferSize 5

int in = 0;
int buffer_raju[BufferSize];
int buffer_saju[BufferSize];
int raju = 0;
int saju = 0;
pthread_mutex_t mutex;

int randnum()
{
    time_t t;
    srand((unsigned)time(&t));
    return (rand() % 6) + 1;
}

void *game(void *pno)
{
    int item;
    int pl = *((int *)pno);
    for (int i = 0; i < BufferSize; i++)
    {
        item = randnum();
        sleep(1);
        pthread_mutex_lock(&mutex);

        if (pl == 1)
        {
            buffer_raju[in] = item;
            raju = raju + item;
            printf("Player %d: Dice value %d at roll %d\n", pl, item, in + 1);
            sleep(1);
        }
        else if (pl == 2)
        {
            buffer_saju[in] = item;
            saju = saju + item;
            printf("Player %d: Dice value %d at roll %d\n", pl, item, in + 1);
            sleep(2);
        }

        in = (in + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{

    while (1)
    {
        if (raju == saju)
        {
            raju = 0;
            saju = 0;
            pthread_t player[2];
            pthread_mutex_init(&mutex, NULL);

            int p[2] = {1, 2};

            for (int i = 0; i < 2; i++)
            {
                pthread_create(&player[i], NULL, &game, (void *)&p[i]);
            }

            for (int i = 0; i < 2; i++)
            {
                pthread_join(player[i], NULL);
            }

            pthread_mutex_destroy(&mutex);
        }
        else if (raju > saju)
        {
            printf("Raju Winner");
            break;
        }
        else
        {
            printf("Saju Winner");
            break;
        }
    }

    return 0;
}
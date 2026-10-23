
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define THREADS 4
#define ITERATIONS 50000

long long counter = 0;
sem_t semaphore;

void *increment_counter(void *arg)
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        sem_wait(&semaphore);
        counter++;
        sem_post(&semaphore);
    }

    return NULL;
}

int main(void)
{
    pthread_t threads[THREADS];

    if (sem_init(&semaphore, 0, 1) != 0)
    {
        perror("sem_init");
        return 1;
    }

    for (int i = 0; i < THREADS; i++)
    {
        if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0)
        {
            perror("pthread_create");
            sem_destroy(&semaphore);
            return 1;
        }
    }

    for (int i = 0; i < THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Counter = %lld\n", counter);
    printf("Expected Counter = %d\n", THREADS * ITERATIONS);

    sem_destroy(&semaphore);
    return 0;
}

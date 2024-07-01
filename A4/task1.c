#include <pthread.h>   
#include <stdio.h>
#include <string.h>
#include <semaphore.h>

#define MAX 10
#define BUFLEN 6
#define NUMTHREAD 2

void *consumer(void *id);
void *producer(void *id);

char buffer[BUFLEN];
char source[BUFLEN+1];
int pCount = 0;
int cCount = 0;
int buflen = 0;

sem_t mutex;
sem_t full;
sem_t empty;
int thread_id[NUMTHREAD]  = {0,1};

int i = 0; 
int j = 0; 

int main()
{
    pthread_t thread[NUMTHREAD];

    strcpy(source,"abcdef");

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFLEN);

    pthread_create(&thread[0], NULL, producer, &thread_id[0]);
    pthread_create(&thread[1], NULL, consumer, &thread_id[1]);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}

void *producer(void *id)
{
    int *myid = (int *)id;
    while(pCount < MAX)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[i] = source[i % BUFLEN];
        printf("%d produced  %c  by Thread  %d\n", pCount, buffer[i], *myid);
        i = (i + 1) % BUFLEN;
        buflen++;
        pCount++;
        sem_post(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
}

void *consumer(void *id)
{
    int *myid = (int *)id;
    while(cCount < MAX)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        printf("%d consumed  %c  by Thread  %d\n", cCount, buffer[j], *myid);
        j = (j + 1) % BUFLEN;
        buflen--;
        cCount++;
        sem_post(&mutex);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threads(void *num) {
    for (int i = 0; i < 5; i++) {
        printf("Thread %d prints %d\n", *(int *)num, *(int *)num * 5 + i + 1);
    }
    return NULL;
}

int main() {
    pthread_t num[5];
    int i;
    for (i = 0; i <= 4; i++) {
        pthread_create(&num[i], NULL, threads, &i);
        pthread_join(num[i], NULL);
    }
}
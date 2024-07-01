#include <stdio.h>
#include <pthread.h>

void *thread(void *num) {
    int id = *(int *)num;
    printf("Thread-%d running\n", id);
    printf("Thread-%d closed\n", id);
    return NULL;
}

int main() {
    pthread_t num[5];
    int i;
    for (i = 1; i <= 5; i++) {
        pthread_create(&num[i], NULL, thread, &i);
        pthread_join(num[i], NULL);
    }
}
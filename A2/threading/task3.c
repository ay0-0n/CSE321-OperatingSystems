#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int ascii(const char *str)
{
    int sum = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        sum += str[i];
    }
    return sum;
}

void *thread(void *arg)
{
    char *str = (char *)arg;
    int *res = (int *)malloc(sizeof(int));
    if (res == NULL)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    *res = ascii(str);

    return res;
}

int main()
{
    char inp1[100], inp2[100], inp3[100];

    printf("Enter the first string: ");
    fgets(inp1, sizeof(inp1), stdin);
    printf("Enter the second string: ");
    fgets(inp2, sizeof(inp2), stdin);
    printf("Enter the third string: ");
    fgets(inp3, sizeof(inp3), stdin);

    pthread_t thread1, thread2, thread3;
    int *res1, *res2, *res3;

    pthread_create(&thread1, NULL, thread, (void *)strdup(inp1));
    pthread_create(&thread2, NULL, thread, (void *)strdup(inp2));
    pthread_create(&thread3, NULL, thread, (void *)strdup(inp3));

    pthread_join(thread1, (void **)&res1);
    pthread_join(thread2, (void **)&res2);
    pthread_join(thread3, (void **)&res3);

    if (*res1 == *res2 && *res2 == *res3)
    {
        printf("Youreka\n");
    }
    else if (*res1 == *res2 || *res2 == *res3 || *res1 == *res3)
    {
        printf("Miracle\n");
    }
    else
    {
        printf("Hasta la vista\n");
    }

    free(res1);
    free(res2);
    free(res3);

    return 0;
}

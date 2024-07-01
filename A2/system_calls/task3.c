#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int a = fork();
    int b = fork();
    int c = fork();

    if (a != 0 && b != 0 && c != 0) {
        FILE *fp = fopen("count.txt", "w+");
        fprintf(fp, "%d", 1);
        fclose(fp);
    }

    if (a == 0 && b != 0 && c != 0) {
        sleep(1);
        int pid = getpid();
        if (pid % 2 != 0) {
            fork();
            int count;
            FILE *fp = fopen("count.txt", "r+");
            fscanf(fp, "%d", &count);
            count++;
            rewind(fp);
            fprintf(fp, "%d", count);
            fclose(fp);
        }
    }

    if (a != 0 && b == 0 && c != 0) {
        sleep(2);
        int pid = getpid();
        if (pid % 2 != 0) {
            fork();
            int count;
            FILE *fp = fopen("count.txt", "r+");
            fscanf(fp, "%d", &count);
            count++;
            rewind(fp);
            fprintf(fp, "%d", count);
            fclose(fp);
        }
    }

    if (a != 0 && b != 0 && c == 0) {
        sleep(3);
        int pid = getpid();
        if (pid % 2 != 0) {
            fork();
            int count;
            FILE *fp = fopen("count.txt", "r+");
            fscanf(fp, "%d", &count);
            count++;
            rewind(fp);
            fprintf(fp, "%d", count);
            fclose(fp);
        }
    }

    if (a != 0 && b != 0 && c != 0) {
        sleep(4);
        int res;
        FILE *fp = fopen("count.txt", "r");
        fscanf(fp, "%d", &res);
        fclose(fp);
        printf("Total processes created: %d\n", res);
    }

    return 0;
}

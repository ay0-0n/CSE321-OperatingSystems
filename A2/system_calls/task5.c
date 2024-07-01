#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t c_pid, gc_pid1, gc_pid2, gc_pid3;

    printf("1. Parent process ID: %d\n", getpid());

    c_pid = fork();
    if (c_pid == 0) {
        printf("2. Child process ID: %d\n", getpid());

        gc_pid1 = fork();
        if (gc_pid1 == 0) {
            printf("3. Grand Child process ID: %d\n", getpid());
        } else {
            wait(NULL);
            gc_pid2 = fork();
            if (gc_pid2 == 0) {
                printf("4. Grand Child process ID: %d\n", getpid());
            } else {
                wait(NULL);
                gc_pid3 = fork();
                if (gc_pid3 == 0) {
                    printf("5. Grand Child process ID: %d\n", getpid());
                } else {
                    wait(NULL);
                }
            }
        }
    } else {
        wait(NULL);
    }

    return 0;
}
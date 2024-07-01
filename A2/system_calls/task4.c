#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {  
    pid_t pid = fork();
    
    if (pid == 0) {
        execv("./sort", argv);
    } else {
        wait(NULL);
        execv("./oddeven", argv);
    }

    return 0;
}
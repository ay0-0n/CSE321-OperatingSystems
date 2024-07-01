#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t c_pid, gc_pid;
    c_pid = fork();
    if (c_pid == 0){
        gc_pid = fork();

        if (gc_pid==0){
            printf("I am grandchild\n");
        }else{
            wait(NULL);
            printf("I am child\n");
        }
    }else{
        wait(NULL);
        printf("I am parent\n");
    }
}
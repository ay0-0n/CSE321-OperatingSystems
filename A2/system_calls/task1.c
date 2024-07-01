#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char* argv[]){
    int fd;
    char buffer[100];
    char* file = argv[1];
    fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0777);
    if(fd != -1)
    {
        printf("Enter a string: ");
        fgets(buffer, 100, stdin);
        while(strcmp(buffer, "-1\n") != 0){
            write(fd, buffer, strlen(buffer));
            printf("Enter a string: ");
            fgets(buffer, 100, stdin);
        }
    }
    close(fd);
}
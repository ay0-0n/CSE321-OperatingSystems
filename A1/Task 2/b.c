#include<stdio.h>
#include <string.h>

int main(){
    FILE *f_inp, *f_out;
    char string[100];
    f_inp = fopen("input.txt", "r");
    f_out = fopen("output.txt", "w");

    fgets(string, 100, (FILE*)f_inp);

    char *str = strtok(string, " ");

    while (str != NULL)
    {
        fputs(str, f_out);
        str = strtok(NULL, " ");

        if(str != NULL){
            fputs(" ", f_out);
        }
    }

    fclose(f_inp);
    fclose(f_out);
}
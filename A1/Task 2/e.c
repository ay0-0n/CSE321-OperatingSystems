#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char str[100];
    scanf("%s",str);

    char *front = str;
    char *back  = str + (strlen(str)-1);

    int flag = 1;

    while (front < back){
        if (*front != *back){
            flag = 0;
            break;
        }
        front++;
        back--;
    } 

    char *res = (flag == 1)? "Palindrome" : "Not Palindrome";

    printf("%s\n",res);
}
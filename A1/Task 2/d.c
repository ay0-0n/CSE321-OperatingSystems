#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char mail[100];
    scanf("%s",mail);
    char checker[] = "@sheba.xyz"; 
    
    if (strstr(mail, checker) != NULL){
        printf("Email address is okay\n");
    }else{
        printf("Email address is outdated\n");
    }
}
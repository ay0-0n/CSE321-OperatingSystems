#include<stdio.h>
#include <string.h>
#include <ctype.h>

void check(char pass[], int len, int flag[] ){
    char sc[] = "_ $#@";

    for (int i=0 ; i< len; i++){
        if(flag[0]!=1){
            if(islower(pass[i])){
                flag[0] = 1;
            }
        }
        if(flag[1]!=1){
            if(isupper(pass[i])){
                flag[1] = 1;
            }
        }
        if(flag[2]!=1){
            if(isdigit(pass[i])){
                flag[2] = 1;
            }
        }
        if(flag[3]!=1){
            if(strchr(sc, pass[i]) != NULL){
                flag[3] = 1;
            }
        }
    }
}

int main(){
    char pass[100];
    scanf("%s", pass);
    int len = strlen(pass);
    char data[4][30] = {"Lowercase character","Uppercase character","Digit","Special character"};
    int flag[4] = {0, 0, 0, 0};

    check(pass,len, flag);

    char res[100] = "";
    for (int i=0; i<4; i++){
        if (flag[i] == 0){
            strcat(res, data[i]);
            strcat(res, " missing, ");
        }
    }
    if(res[0] == '\0'){
        printf("OK\n");
    }else{
        res[strlen(res) - 2] = '\0';
        printf("%s\n",res);
    }
}

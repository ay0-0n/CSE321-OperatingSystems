#include<stdio.h>

double add(double a, double b){
    return a + b;
}

double sub(double a, double b){
    return a - b;
}

double mul(double a, double b){
    return a * b;
}

int main(){
    double num1, num2;
    char operator;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Enter an operator: ");
    scanf(" %c", &operator);

    if (num1 > num2){ 
        printf("%f",sub(num1, num2));
    }else if (num1 < num2){
        printf("%f",add(num1, num2));
    }else if (num1 == num2){
        printf("%f",mul(num1, num2));
    }
}
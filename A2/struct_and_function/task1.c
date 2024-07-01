#include <stdio.h>

struct item{
    int quantity;
    float unitPrice;
};

int main(){
    struct item paratha, vegetable, water;
    int num;
    float bill, payment;

    printf("Quantity Of Paratha: ");
    scanf("%d", &paratha.quantity);
    printf("Unit Price: ");
    scanf("%f", &paratha.unitPrice);

    printf("Quantity Of Vegetables: ");
    scanf("%d", &vegetable.quantity);
    printf("Unit Price: ");
    scanf("%f", &vegetable.unitPrice);

    printf("Quantity Of Mineral Water: ");
    scanf("%d", &water.quantity);
    printf("Unit Price: ");
    scanf("%f", &water.unitPrice);

    printf("Number of People: ");
    scanf("%d", &num);

    bill = paratha.quantity * paratha.unitPrice + vegetable.quantity * vegetable.unitPrice + water.quantity * water.unitPrice;
    
    payment = bill / num;

    printf("Individual people will pay: %.2f tk\n", payment);

}
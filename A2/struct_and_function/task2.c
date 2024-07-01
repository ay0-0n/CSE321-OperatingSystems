#include <stdio.h>

int isPerfect(int num) {
    int sum = 0;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return (sum == num);
}

void printPerfectNums(int l, int r) {
    for (int i = l; i <= r; i++) {
        if (isPerfect(i)) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int l, r;
    printf("Enter Range:\n");
    scanf("%d", &l);
    scanf("%d", &r);

    printPerfectNums(l, r);

    return 0;
}

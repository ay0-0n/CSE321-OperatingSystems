#include <stdio.h>
#include <stdlib.h>

void srt(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]){
    int n = argc-1;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i+1]);
    }

    srt(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
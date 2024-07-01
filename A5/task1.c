#include <stdio.h>
#include <stdbool.h>

void subtract_matrix(int rows, int cols, int mat_a[][cols], int mat_b[][cols], int mat_res[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat_res[i][j] = mat_a[i][j] - mat_b[i][j];
        }
    }
}

bool is_less_than_or_equals(int length, int array_a[], int array_b[]) {
    for (int i = 0; i < length; i++) {
        if (array_a[i] > array_b[i]) {
            return false;
        }
    }
    return true;
}

void add_array_values(int length, int array_a[], int array_b[], int array_res[]) {
    for (int i = 0; i < length; i++) {
        array_res[i] = array_a[i] + array_b[i];
    }
}

int main(){
    int n = 5; // Number of processes
    int m = 4; // Number of resources
    int alloc[5][4] = { { 0, 1, 0, 3 }, // P0	// Allocation Matrix
                        { 2, 0, 0, 0 }, // P1
                        { 3, 0, 2, 0 }, // P2
                        { 2, 1, 1, 5 }, // P3
                        { 0, 0, 2, 2 } }; // P4
 
    int max[5][4] = { { 6, 4, 3, 4 }, // P0	// MAX Matrix
                      { 3, 2, 2, 1 }, // P1
                      { 9, 1, 2, 6 }, // P2
                      { 2, 2, 2, 8 }, // P3
                      { 4, 3, 3, 7 } }; // P4

    int avail[4] = { 3, 3, 2, 1 };

    int need[n][m];
    subtract_matrix(n, m, max, alloc, need);

    bool finished[n];
    for (int i = 0; i < n; i++) {
        finished[i] = false;
    }

    int completed_processes = 0;
    while (completed_processes < n) {
        bool ran_at_least_one = false;
        for (int i = 0; i < n; i++) {
            if (!finished[i] && is_less_than_or_equals(m, need[i], avail)) {
                finished[i] = true;
                ran_at_least_one = true;
                completed_processes++;
                add_array_values(m, avail, alloc[i], avail);
            }
        }

        if (!ran_at_least_one) {
            printf("Deadlock Ahead\n");
            return 0;
        }
    }

    printf("Safe here\n");
    return 0;
}
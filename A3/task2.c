#include<stdio.h>

struct process {
    int id;
    int bt;
    int ct;
    int tat;
    int wt;
};

void waiting_CompletionTime(struct process proc[], int n, int quantum) {
    int rem_bt[n];
    int t = 0;

    for (int i = 0; i < n; i++) {
        rem_bt[i] = proc[i].bt;
    }

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;

                if (rem_bt[i] > quantum) {
                    t += quantum;

                    rem_bt[i] -= quantum;
                }
                else {
                    t = t + rem_bt[i];

                    proc[i].wt = t - proc[i].bt;
                    proc[i].ct = proc[i].wt + proc[i].bt;

                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1) {
            break;
        }
    }
}

void turnAroundTime(struct process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;
    }
}

void printTimes(struct process proc[], int n) {
    printf("P            BT           WT           TAT           CT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d           %d           %d           %d           %d\n", proc[i].id, proc[i].bt, proc[i].wt, proc[i].tat, proc[i].ct);
    }
}

int main() {
    struct process proc[100];
    int n, i, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the burst time for P%d: ", i+1);
        scanf("%d", &proc[i].bt);
        proc[i].id = i+1;
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);


    waiting_CompletionTime(proc, n, quantum);
    turnAroundTime(proc, n);
    printTimes(proc, n);
    return 0;
}

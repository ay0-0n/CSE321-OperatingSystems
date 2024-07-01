#include<stdio.h>
#include<limits.h>

struct process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void waiting_CompletionTime(struct process proc[], int n) {
    int rt[n];
    for (int i = 0; i < n; i++) {
        rt[i] = proc[i].bt;
    }
    int complete = 0;
    int t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    int check = 0;
    while (complete != n) {

        for (int j = 0; j < n; j++) {
            if ((proc[j].at <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm--;
        

        if (minm == 0) {
            minm = INT_MAX;
        }
        if (rt[shortest] == 0) {
            complete++;
            check = 0;
            finish_time = t + 1;
            proc[shortest].wt = finish_time - proc[shortest].bt - proc[shortest].at;
            if (proc[shortest].wt < 0) {
                proc[shortest].wt = 0;
            }
            proc[shortest].ct = finish_time;
        }
        t++;
    }
}

void turnAroundTime(struct process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;
    }
}

void printTimes(struct process proc[], int n) {
    printf("P           AT           BT          WT          TAT         CT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d           %d           %d           %d           %d           %d\n", proc[i].id, proc[i].at, proc[i].bt, proc[i].wt, proc[i].tat, proc[i].ct);
    }
}

int main() {
    struct process proc[100];
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for P%d: ", i+1);
        scanf("%d %d", &proc[i].at, &proc[i].bt);
        proc[i].id = i+1;
    }
    waiting_CompletionTime(proc, n);
    turnAroundTime(proc, n);
    printTimes(proc, n);
    return 0;
}

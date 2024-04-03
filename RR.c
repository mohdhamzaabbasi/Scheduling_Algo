#include <stdio.h>

struct Process {
    int id;
    int burst;
};

void roundRobin(struct Process processes[], int n, int quantum) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burst;
    }

    int time = 0;

    while (1) {
        int completed = 1;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                completed = 0;
                int executeTime = (remainingTime[i] > quantum) ? quantum : remainingTime[i];
                time += executeTime;
                remainingTime[i] -= executeTime;

                if (remainingTime[i] == 0) {
                    printf("Process %d:\n", processes[i].id);
                    printf("Turnaround Time: %d\n", time);
                }
            }
        }
        if (completed) {
            break;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        processes[i].id = i + 1;
        printf("Burst time: ");
        scanf("%d", &processes[i].burst);
    }

    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    roundRobin(processes, n, quantum);

    return 0;
}

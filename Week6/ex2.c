#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define max_BT 100000

struct process {
    int ID, AT, BT, CT, TAT, WT;
    bool is_done;
};

void sort(int n, struct process *processes) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (processes[j].AT > processes[j + 1].AT
            || (processes[j].AT == processes[j + 1].AT && processes[j].BT > processes[j + 1].BT)) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes:\n");
    scanf("%d", &n);
    struct process processes[n];
    printf("Enter BT and AT for each process: \n");
    for (int i = 0; i < n; i++) {
        processes[i].ID = i + 1;
        int input;
        scanf("%d", &input);
        processes[i].BT = input;
        scanf("%d", &input);
        processes[i].AT = input;
        processes[i].is_done = false;
    }

    sort(n, processes);

    int time = 0;
    int flag = 1;

    // do while we have an unfinished process
    while (flag) {
        flag = 0;
        int min_index = -1;
        int min_BT = max_BT + 1;

        // find process with min bt and at <= current time
        for (int i = 0; i < n; i++) {
            if (!processes[i].is_done && processes[i].AT <= time && processes[i].BT < min_BT) {
                min_BT = processes[i].BT;
                min_index = i;
            }
        }
        if (min_index == -1) {
            time++;
            continue;
        }

        processes[min_index].CT = time + processes[min_index].BT;
        processes[min_index].TAT = processes[min_index].CT - processes[min_index].AT;
        processes[min_index].WT = processes[min_index].TAT - processes[min_index].BT;
        processes[min_index].is_done = true;

        time = processes[min_index].CT;

        for (int i = 0; i < n; i++) {
            if (!processes[i].is_done)  {
                flag = 1;
            }
        }
    }

    int TAT_sum = 0;
    int WT_sum = 0;
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", processes[i].ID);
        printf("BT: %d\n", processes[i].BT);
        printf("AT: %d\n", processes[i].AT);
        printf("CT: %d\n", processes[i].CT);
        printf("TAT: %d\n", processes[i].TAT);
        printf("WT: %d\n\n", processes[i].WT);
        TAT_sum += processes[i].TAT;
        WT_sum += processes[i].WT;
    }

    printf("Average TAT: %f\n", (float) TAT_sum / (float) n);
    printf("Average WT: %f\n", (float) WT_sum / (float) n);

    return 0;
}

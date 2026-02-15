//If AT ≠ 0 → order depends on arrival times (earliest first)
#include <stdio.h>

int main() {
    int n, total_wt, total_tat ;
    int at[20], bt[20], ct[20], tat[20], wt[20], pid[20];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {  
        pid[i] = i + 1;
        printf("Enter Arrival Time for P%d: ", pid[i]);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }
    // Sorting by Arrival Time (FCFS)
    for(int i = 0; i < n-1; i++) { // upto n-1, because j moves forward to compare --> for last element i = n-1, j=n --> out of bounds --> Ex: n=5, i=4, last element index = 3, j=5 --> out of bounds
        for(int j = i+1; j < n; j++) {
            if(at[i] > at[j]) // If arrival time of process i is greater than that of process j, swap them
            {
                int temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp; // AT swapped so that order is correct
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    // Completiion of First process --> starts at its AT, completes after its BT
    ct[0] = at[0] + bt[0];

    // Remaining processes
    for(int i = 1; i < n; i++) {
        if(ct[i-1] < at[i]) //previous process finished before next arrived --> CPU waits/ idle
            ct[i] = at[i] + bt[i]; // EX: prev CT =5, Current AT = 8 --> CPU idle from 5 to 8, current process starts at 8 --> CT= 8 + BT
        else
            ct[i] = ct[i-1] + bt[i]; //previous process finished after next arrived --> no idle time, starts immediately after completion of previous process --> completes at (prev CT + BT)
            // EX: Previous CT = 5, curr AT = 4 --> curr_process starts at 5 --> CT = 5 + BT

    }

    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
printf("\nAverage Waiting Time = %.2f", total_wt / n);
printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
return 0;
}

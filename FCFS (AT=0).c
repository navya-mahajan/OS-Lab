// FCFS executes processes in order of arrival.
// If all AT = 0 → order is input order

#include <stdio.h>
int main() {
    int n;
    int bt[20], ct[20], tat[20], wt[20]; // arrival time = 0
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i+1); // Burst Time: the total CPU time required by the process
        scanf("%d", &bt[i]);
    }
    ct[0] = bt[0]; // all arrival times are zero
    
    // remaining processes
    for(int i = 1; i<n; i++) {
        ct[i] = ct[i-1] + bt[i]; // Completion time of current process = end time of previous process + its own burst time
    }
        for(int i= 0; i<n; i++) {
        tat[i] = ct[i]; // Turnaround Time (TAT) = CT - AT; duration from when the process enters the queue until it completes

        wt[i] = tat[i] - bt[i]; // Waiting time (WT) = TAT - BT; total the process waited out of total time it took for execution
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("\nBy FCFS approach\n");
    printf("\nPID\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], ct[i], tat[i], wt[i]);     
    }
printf("\nAverage Waiting Time = %.2f", total_wt / n);
printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
return 0;

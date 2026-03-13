#include <stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int rem_bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int done;
};
void schedule(struct process p[], int n)
{
    int time = 0;
    int complete = 0;
    while (complete < n)
    {
        int index = -1;
        int min_rem_bt = 12345;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= time && !p[i].done)
            {
                if (p[i].rem_bt < min_rem_bt)
                {
                    min_rem_bt = p[i].rem_bt;
                    index = i;
                }
                else if (p[i].rem_bt == min_rem_bt)
                {
                    if (index != -1 && p[i].at < p[index].at)
                    {
                        index = i;
                    }
                }
            }
        }

        if (index == -1) {
            time++;
        }
        else {
            if (p[index].rem_bt == p[index].bt) {
                p[index].rt = time - p[index].at;
            }
            p[index].rem_bt--;
            time++;

            if (p[index].rem_bt == 0) {
                p[index].ct = time;
                p[index].tat = p[index].ct - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;
                p[index].done = 1;
                complete++;
            }
        }
    }
}
void display(struct process p[], int n) {
    float total_wt = 0, total_tat = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        p[i].done = 0;
        printf("Enter arrival time and burst time for process %d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rem_bt = p[i].bt;
    }
    schedule(p, n);
    display(p, n);
    return 0;
}

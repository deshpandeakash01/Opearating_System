#include<stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int pre;
    int rem_bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int done;
};
void schedule(struct process p[],int n)
{
    int time=0;
    int completed=0;
    while(completed<n)
    {
        int index=-1;
        int min=12345;
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time&&!p[i].done)
                if(p[i].pre<min)
                {
                    min=p[i].rem_bt;
                    index=i;
                }
            else if(p[i].pre==min)
            {
                if(index != -1 && p[i].at < p[index].at)
                {
                        index = i;
                }
            }
        }
        if(index==-1) time++;
        else
        {
            if(p[index].rem_bt==p[index].bt)
            {
                p[index].rt=time-p[index].at;
            }
            p[index].rem_bt--;
            time++;
            if(p[index].rem_bt==0)
            {
                p[index].ct = time;
                p[index].tat = p[index].ct - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;
                p[index].done = 1;
                completed++;
            }
        }
    }
}
void display(struct process p[], int n) {
    float total_wt = 0, total_tat = 0;

    printf("\nPID\tAT\tBT\tPRE\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].pre,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
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
        p[i].pid = i+1;
        p[i].done = 0;
        printf("Enter AT,BT and PRE for P%d: ", p[i].pid);
        scanf("%d %d %d", &p[i].at, &p[i].bt,& p[i].pre);
        p[i].rem_bt=p[i].bt;
    }
    schedule(p, n);
    display(p, n);
    return 0;
}

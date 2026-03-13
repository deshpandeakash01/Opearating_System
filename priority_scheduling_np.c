#include<stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int pre;
    int ct;
    int tat;
    int wt;
    int rt;
    int done;

};
void schedule(struct process p[],int n)
{
    int completed=0;
    int time=0;
    while(completed<n)
    {
        int I=-1;
        int min=12345;
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time&&!p[i].done&&p[i].pre<min)
            {
                min=p[i].pre;
                I=i;
            }
        }
            if(I==-1)time++;
            else
            {
                p[I].rt=time-p[I].at;
                time+=p[I].bt;
                p[I].ct=time;
                p[I].tat=p[I].ct-p[I].at;
                p[I].wt=p[I].tat-p[I].bt;
                p[I].done=1;
                completed++;
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
    }
    schedule(p, n);
    display(p, n);
    return 0;
}


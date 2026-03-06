#include<stdio.h>
struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int done;
};
void shcedule(struct process p[],int n)
{
    int time=0;
    int complete=0;
    while(complete<n)
    {
        int index=-1;
        int min_bt=123234;
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time&&!p[i].done&&p[i].bt<min_bt)
            {
                min_bt=p[i].bt;
                index=i;
            }
        }
        if(index==-1) time++;
        else {
            p[index].rt=time-p[index].at;
            time+=p[index].bt;
            p[index].ct=time;
            p[index].tat=p[index].ct-p[index].at;
            p[index].wt=p[index].tat-p[index].bt;
            p[index].done=1;
            complete++;
        }
    }
}
void display(struct process p[], int n) {
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }
}
int main()
{
    int n;
    printf("enter number of process : ");
    scanf("%d",&n);
    struct process p[n];
    //printf("\nenter arrival and burst time for all the process : \n");
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;  // Assign process ID
        p[i].done=0;
        printf("Enter AT and BT for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }
    shcedule(p,n);
    display(p,n);
}

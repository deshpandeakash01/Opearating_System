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
};
void sort(struct process p[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (p[i].at > p[j].at)
            {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
void shcedule(struct process p[],int n)
{
    int time=0;
    for(int i=0;i<n;i++)
    {
        if(time<p[i].at)
        {
            time=p[i].at;
        }
        p[i].rt = time - p[i].at;
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

    }
}
void sort_after_shceduling(struct process p[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (p[i].pid > p[j].pid)
            {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
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
        printf("Enter AT and BT for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    sort(p,n);
    shcedule(p,n);
    display(p,n);

}

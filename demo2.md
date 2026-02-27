#include<stdio.h>
int smallest(int arr[],int n)
{
    int min=arr[0];
    int loc=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
            loc=i;
        }
    }
    printf("minimum element is at : %d",loc);
}
int main()
{
    int n;
    printf("size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements of array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    smallest(a,n);
}

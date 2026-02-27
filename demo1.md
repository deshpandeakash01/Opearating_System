
#include <stdio.h>
int LinearSearch(int a[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(a[i] == key) {
            return i;
        }
    }
    return -1;
}
int BinarySearch(int a[], int n, int key) {
    int l = 0, h = n - 1;
    while(l <= h) {
        int m = l + (h - l) / 2;
        if(a[m] == key) {
            return m;
        }
        else if(a[m] < key) {
            l = m + 1;
        }
        else {
            h = m - 1;
        }
    }
    return -1;
}
int main() {
    int n,key;
    printf("Size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the elements of array (sorted for binary search):\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("enter key element to search : ");
    scanf("%d",&key);
    int f = LinearSearch(a, n, key);
    int f2 = BinarySearch(a, n, key);
    printf("\nLinear search result at index : %d", f);
    printf("\nBinary search result at index : %d", f2);
}

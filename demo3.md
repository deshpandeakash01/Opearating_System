#include <stdio.h>

int hasDuplicates(int a[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements of array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if(hasDuplicates(a, n)) {
        printf("Array contains duplicates.\n");
    } else {
        printf("Array does not contain duplicates.\n");
    }

    return 0;
}

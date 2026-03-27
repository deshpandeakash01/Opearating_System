
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void edf(int cap[], int dead[], int period[], int n)
{
    int hyper = period[0];
    for (int i = 1; i < n; i++) {
        hyper = lcm(hyper, period[i]);
    }

    printf("\nScheduling occurs for %d ms\n\n", hyper);

    int remaining[n];
    int abs_dead[n];

    for (int i = 0; i < n; i++) {
        remaining[i] = 0;
        abs_dead[i] = dead[i];
    }

    int last = -2;

    for (int t = 0; t < hyper; t++)
    {
        for (int i = 0; i < n; i++) {
            if (t % period[i] == 0) {
                remaining[i] += cap[i];
                abs_dead[i] = t + dead[i];
            }
        }

        int chosen = -1;
        int min_dead = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0 && abs_dead[i] < min_dead) {
                min_dead = abs_dead[i];
                chosen = i;
            }
        }

        if (chosen != -1) {
            if (last != chosen) {
                printf("%dms onwards: Task %d is running\n", t, chosen+1);
                last = chosen;
            }
            remaining[chosen]--;
        } else {
            if (last != -1) {
                printf("%dms onwards: CPU is idle\n", t);
                last = -1;
            }
        }
    }
}

int main()
{
    int n;
    double sum = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int cap[n], dead[n], period[n];
    printf("Enter the capacity, deadline, period\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]: ", i+1);
        scanf("%d %d %d", &cap[i], &dead[i], &period[i]);

        sum += (double)cap[i] / period[i];
    }

    if (sum <= 1)
    {
        edf(cap, dead, period, n);
    }
    else
    {
        printf("Not possible\n");
    }

    return 0;
}

#include <stdio.h>
#include <math.h>

struct process {
    int id;
    int c;      // Computation time
    int p;      // Period
    int rem;    // Remaining execution time
};

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void schedule(struct process p[], int n) {
    // Sort tasks by ascending period
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].p > p[j].p) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Compute hyperperiod
    int hyper = p[0].p;
    for (int i = 1; i < n; i++) {
        hyper = lcm(hyper, p[i].p);
    }

    printf("LCM = %d\n\n", hyper);
    printf("Rate Monotone Scheduling:\n");
    printf("PID\tBurst\tPeriod\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", p[i].id, p[i].c, p[i].p);
    }

    // Utilization test
    double util = 0;
    for (int i = 0; i < n; i++) {
        util += (double)p[i].c / p[i].p;
    }
    double bound = n * (pow(2.0, 1.0 / n) - 1.0);
    printf("\n%f <= %f => %s\n", util, bound, (util <= bound) ? "true" : "false");
    printf("Scheduling occurs for %d ms\n\n", hyper);

    // Timeline
    for (int time = 0; time < hyper; time++) {
        for (int i = 0; i < n; i++) {
            if (time % p[i].p == 0) {
                p[i].rem = p[i].c;
            }
        }

        int index = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].rem > 0) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            if (p[index].rem == p[index].c) {
                printf("%dms onwards: Process %d running\n", time, p[index].id);
            }
            p[index].rem--;
        } else {
            printf("%dms onwards: CPU is idle\n", time);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    printf("Enter the CPU burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].c);
    }

    printf("Enter the time periods:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].p);
        p[i].id = i + 1;
        p[i].rem = 0;
    }

    schedule(p, n);
    return 0;
}

#include <stdio.h>

#define MAX_P 10  // Max processes
#define MAX_R 10  // Max resources

int main() {
    int n, m; // n = number of processes, m = number of resources
    int alloc[MAX_P][MAX_R], max[MAX_P][MAX_R], need[MAX_P][MAX_R], avail[MAX_R];
    int finish[MAX_P] = {0}, safeSeq[MAX_P];
    int i, j, k;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the Allocation matrix (%d x %d):\n", n, m);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the Max matrix (%d x %d):\n", n, m);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the Available resources (%d):\n", m);
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate Need matrix = Max - Allocation
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int count = 0;
    while (count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if (finish[i] == 0) {
                for(j = 0; j < m; j++) {
                    if (need[i][j] > avail[j])
                        break;
                }
                if (j == m) {
                    for(k = 0; k < m; k++)
                        avail[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("\nSystem is not in a safe state.\n");
            return 1;
        }
    }

    printf("\nSystem is in a safe state.\nSafe sequence is: ");
    for(i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}

/*Implement 0/1 Knapsack problem using dynamic
programming.*/

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int *val = (int *)malloc(n * sizeof(int));
    int *wt = (int *)malloc(n * sizeof(int));

    if (val == NULL || wt == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int result = knapsack(W, wt, val, n);

    printf("Maximum value in knapsack of capacity %d = %d\n", W, result);

    free(val);
    free(wt);
    return 0;
}

/* OUTPUT
Enter the number of items: 4
Enter the values of the items:
10 40 30 50
Enter the weights of the items:
5 4 6 3
Enter the capacity of the knapsack: 10
Maximum value in knapsack of capacity 10 = 90
*/

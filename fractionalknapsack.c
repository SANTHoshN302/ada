/*Implement fractional knapsack problem using Greedy
technique.*/

#include <stdio.h>
#include <stdlib.h>


struct Item {
    int value;
    int weight;
    float ratio;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    if (item2->ratio > item1->ratio) return 1;
    else if (item2->ratio < item1->ratio) return -1;
    else return 0;
}

float fractionalKnapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);

    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
          
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
     
            totalValue += items[i].ratio * capacity;
            break; 
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item *items = (struct Item *)malloc(n * sizeof(struct Item));
    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].value);
    }

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in knapsack = %.2f\n", maxValue);

    free(items);
    return 0;
}

/* OUTPUT
Enter the number of items: 3
Enter the values of the items:
60 100 120
Enter the weights of the items:
10 20 30
Enter the capacity of the knapsack: 50
Maximum value in knapsack = 240.00
*/


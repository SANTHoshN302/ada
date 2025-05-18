/*Sort a given set of N integer elements using Heap Sort
technique and compute its time taken*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int N, int i) {
    int largest = i;          
    int left = 2 * i + 1;     
    int right = 2 * i + 2;   

    if (left < N && arr[left] > arr[largest])
        largest = left;

    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) {
   
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i > 0; i--) {
     
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock(); 

    heapSort(arr, N);

    clock_t end = clock(); 

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    printf("\nTime taken: %f seconds\n", time_taken);

    free(arr);
    return 0;
}

/* OUTPUT
Enter the number of elements: 6
Enter 6 integers:
5 2 8 1 3 9

Sorted array:
1 2 3 5 8 9 
Time taken: 0.000002 seconds
*/


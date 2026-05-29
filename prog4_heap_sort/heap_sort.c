/*
 * Program 4: Heap Sort
 * Sort a given set of N integer elements using Heap Sort
 * technique and compute the time taken.
 *
 * Time Complexity: Best / Average / Worst = O(n log n)
 *
 * ADA Lab - BMS College of Engineering
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left    = 2 * i + 1;
    int right   = 2 * i + 2;

    if (left  < n && arr[left]  > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp      = arr[i];
        arr[i]        = arr[largest];
        arr[largest]  = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    /* Build max-heap */
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    /* Extract elements one by one */
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0]   = arr[i];
        arr[i]   = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d integers: \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start = clock();
    heapSort(arr, n);
    clock_t end   = clock();
    double cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Time taken : %.6f Seconds\n", cpu_time_used);

    free(arr);
    return 0;
}

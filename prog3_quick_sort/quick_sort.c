/*
 * Program 3: Quick Sort
 * Sort a given set of N integer elements using Quick Sort
 * technique and compute the time taken.
 *
 * Time Complexity:
 *   Best Case    : O(n log n)
 *   Average Case : O(n log n)
 *   Worst Case   : O(n^2)
 *
 * ADA Lab - BMS College of Engineering
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int arr[MAX];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high) {
    int pivot = arr[low];   /* using first element as pivot */
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pos = partition(low, high);
        quickSort(low, pos - 1);
        quickSort(pos + 1, high);
    }
}

int main() {
    int n, i;
    clock_t start, end;
    double time_taken;

    srand((unsigned)time(NULL));
    printf("%-10s\t%-20s\n", "N", "Time Taken (seconds)");

    for (n = 10000; n <= 50000; n += 10000) {
        for (i = 0; i < n; i++)
            arr[i] = rand() % 100000;

        start = clock();
        quickSort(0, n - 1);
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%-10d\t%.10lf\n", n, time_taken);
    }

    return 0;
}

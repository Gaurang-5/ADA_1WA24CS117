/*
 * Program 2: Merge Sort
 * Sort a given set of N integer elements using Merge Sort
 * technique and compute the time taken. Run the program for
 * different values of N and record the time taken to sort.
 *
 * Time Complexity: Best / Average / Worst = O(n log n)
 *
 * ADA Lab - BMS College of Engineering
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int arr[MAX], temp[MAX];

void merge(int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
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
            arr[i] = rand() % 500000;

        start = clock();
        mergeSort(0, n - 1);
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%-10d\t%.10lf\n", n, time_taken);
    }

    return 0;
}

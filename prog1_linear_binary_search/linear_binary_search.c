/*
 * Program 1: Linear Search and Binary Search
 * Sort a given set of N integer elements and implement
 * Linear Search and Binary Search. Compare time complexity.
 *
 * ADA Lab - BMS College of Engineering
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

/* Linear Search: O(n) worst case */
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;   /* Found */
    }
    return -1;          /* Not Found */
}

/* Binary Search: O(log n) worst case */
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;         /* Found */
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  /* Not Found */
}

/* Comparison function for qsort */
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[MAX];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &target);

    /* ---------- Linear Search ---------- */
    clock_t start = clock();
    int pos = linearSearch(arr, n, target);
    clock_t end = clock();
    double ls_time = (double)(end - start) / CLOCKS_PER_SEC;

    if (pos != -1)
        printf("\nLinear Search: Found at index %d\n", pos);
    else
        printf("\nLinear Search: Element not found\n");
    printf("Linear Search Time: %lf seconds\n", ls_time);

    /* Sort array for Binary Search */
    qsort(arr, n, sizeof(int), cmp);

    /* ---------- Binary Search ---------- */
    start = clock();
    pos = binarySearch(arr, n, target);
    end = clock();
    double bs_time = (double)(end - start) / CLOCKS_PER_SEC;

    if (pos != -1)
        printf("\nBinary Search: Found at index %d (in sorted array)\n", pos);
    else
        printf("\nBinary Search: Element not found\n");
    printf("Binary Search Time: %lf seconds\n", bs_time);

    /* ---------- Time Complexity Summary ---------- */
    printf("\n--- Time Complexity Comparison ---\n");
    printf("%-20s %-15s %-15s %-15s\n", "Algorithm", "Best Case", "Average Case", "Worst Case");
    printf("%-20s %-15s %-15s %-15s\n", "Linear Search", "O(1)", "O(n)", "O(n)");
    printf("%-20s %-15s %-15s %-15s\n", "Binary Search", "O(1)", "O(log n)", "O(log n)");

    return 0;
}

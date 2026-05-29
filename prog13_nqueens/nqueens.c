/*
 * Program 13: N-Queens Problem – Backtracking
 * Implement "N-Queens Problem" using Backtracking.
 *
 * Place N queens on an N×N board so that no two queens attack
 * each other (same row, column, or diagonal).
 *
 * ADA Lab - BMS College of Engineering
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX], n, count = 0;

/*
 * Check if placing a queen at (row, col) is safe.
 * board[i] stores the row at which the queen is placed in column i.
 */
int isSafe(int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[i] == row ||
            abs(board[i] - row) == abs(i - col))
            return 0;
    }
    return 1;
}

void solve(int col) {
    if (col == n) {
        printf("Solution %d: ", ++count);
        for (int i = 0; i < n; i++)
            printf("(%d,%d) ", i, board[i]);
        printf("\n");
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col)) {
            board[col] = row;
            solve(col + 1);
        }
    }
}

int main() {
    printf("Enter N: ");
    scanf("%d", &n);
    solve(0);
    printf("Total Solutions: %d\n", count);
    return 0;
}

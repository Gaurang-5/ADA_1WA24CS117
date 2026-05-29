/*
 * Program 5: Johnson-Trotter Algorithm
 * Implement Johnson-Trotter algorithm to generate permutations.
 *
 * Time Complexity: O(n * n!)
 *
 * ADA Lab - BMS College of Engineering
 */

#include <stdio.h>

#define MAX 10

int perm[MAX], dir[MAX], n;

/* Print current permutation */
void printPerm() {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

/*
 * Find the largest mobile element.
 * An element perm[i] is mobile if its arrow points to an
 * adjacent smaller element.
 * dir[i] = -1 means pointing left, dir[i] = +1 means pointing right.
 */
int mobile(int *pos) {
    int mob = -1, mobVal = 0;
    for (int i = 0; i < n; i++) {
        int next = i + dir[i];
        if (next >= 0 && next < n && perm[i] > mobVal && perm[i] > perm[next]) {
            mob    = i;
            mobVal = perm[i];
            *pos   = i;
        }
    }
    return mob;
}

void johnsonTrotter() {
    /* Initialise: perm = {1, 2, ..., n}, all dirs = -1 (left) */
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i]  = -1;
    }
    printPerm();

    int chos;
    while (mobile(&chos) != -1) {
        int next = chos + dir[chos];

        /* Swap chosen element with the element it points to */
        int tmp      = perm[chos];
        perm[chos]   = perm[next];
        perm[next]   = tmp;

        int tmpD     = dir[chos];
        dir[chos]    = dir[next];
        dir[next]    = tmpD;

        /* Reverse direction of all elements larger than chosen */
        for (int i = 0; i < n; i++) {
            if (perm[i] > perm[next])
                dir[i] = -dir[i];
        }
        printPerm();
    }
}

int main() {
    printf("Enter n: ");
    scanf("%d", &n);
    johnsonTrotter();
    return 0;
}

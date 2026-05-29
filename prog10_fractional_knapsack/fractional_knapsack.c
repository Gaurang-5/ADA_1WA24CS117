/*
 * Program 10: Fractional Knapsack Problem – Greedy Technique
 * Implement fractional knapsack problem using Greedy technique.
 *
 * Strategy: Sort items by value/weight ratio (descending).
 *           Take items greedily; take fraction of last item if needed.
 *
 * ADA Lab - BMS College of Engineering
 */

#include <stdio.h>

struct Item {
    int value;
    int weight;
};

/* Bubble sort items by value/weight ratio in descending order */
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double r1 = (double)items[i].value / items[i].weight;
            double r2 = (double)items[j].value / items[j].weight;
            if (r1 < r2) {
                struct Item temp = items[i];
                items[i]         = items[j];
                items[j]         = temp;
            }
        }
    }
}

double knapsack(int W, struct Item items[], int n) {
    sortItems(items, n);
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            /* Take whole item */
            W           -= items[i].weight;
            totalValue  += items[i].value;
        } else {
            /* Take fraction */
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    int n = sizeof(items) / sizeof(items[0]);

    printf("%.2f\n", knapsack(W, items, n));
    return 0;
}

# ADA Lab Programs – BMS College of Engineering

**Course:** Analysis and Design of Algorithms (ADA)  
**Department:** Computer Science and Engineering  
**University:** VTU Belagavi (Autonomous College)

---

## Program List

| # | Folder | Program | Technique |
|---|--------|---------|-----------|
| 1 | `prog1_linear_binary_search` | Linear Search & Binary Search | Brute Force / Divide & Conquer |
| 2 | `prog2_merge_sort` | Merge Sort (with timing for N = 10k–50k) | Divide & Conquer |
| 3 | `prog3_quick_sort` | Quick Sort (with timing for N = 10k–50k) | Divide & Conquer |
| 4 | `prog4_heap_sort` | Heap Sort (with timing) | Transform & Conquer |
| 5 | `prog5_johnson_trotter` | Johnson-Trotter Permutation Generator | Decrease & Conquer |
| 6 | `prog6_topological_sort` | Topological Ordering of a Digraph | Graph (Kahn's BFS) |
| 7 | `prog7_kruskal` | Minimum Cost Spanning Tree – Kruskal's | Greedy |
| 8 | `prog8_prim` | Minimum Cost Spanning Tree – Prim's | Greedy |
| 9 | `prog9_dijkstra` | Single Source Shortest Paths – Dijkstra's | Greedy |
| 10 | `prog10_fractional_knapsack` | Fractional Knapsack | Greedy |
| 11 | `prog11_01_knapsack_dp` | 0/1 Knapsack | Dynamic Programming |
| 12 | `prog12_floyd_warshall` | All Pair Shortest Paths – Floyd-Warshall | Dynamic Programming |
| 13 | `prog13_nqueens` | N-Queens Problem | Backtracking |

---

## How to Compile and Run

Each program is a standalone `.c` file. Use GCC:

```bash
gcc program_name.c -o output_name
./output_name
```

**Example – Merge Sort:**
```bash
cd prog2_merge_sort
gcc merge_sort.c -o merge_sort
./merge_sort
```

**Example – N-Queens:**
```bash
cd prog13_nqueens
gcc nqueens.c -o nqueens
./nqueens
# Enter N: 4
```

---

## Time Complexity Summary

| Algorithm | Best | Average | Worst |
|-----------|------|---------|-------|
| Linear Search | O(1) | O(n) | O(n) |
| Binary Search | O(1) | O(log n) | O(log n) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) |
| Johnson-Trotter | O(n·n!) | O(n·n!) | O(n·n!) |
| Topological Sort | O(V+E) | O(V+E) | O(V+E) |
| Kruskal's MST | O(E log E) | O(E log E) | O(E log E) |
| Prim's MST | O(V²) | O(V²) | O(V²) |
| Dijkstra's | O(V²) | O(V²) | O(V²) |
| Fractional Knapsack | O(n log n) | O(n log n) | O(n log n) |
| 0/1 Knapsack DP | O(nW) | O(nW) | O(nW) |
| Floyd-Warshall | O(V³) | O(V³) | O(V³) |
| N-Queens | — | — | O(n!) |

#include <stdio.h>

#define N   7
#define INF 99999

extern int table[N][N];
extern int prev[N][N];

void print_table(int show_diff) {
    int i, j;

    printf("\n      ");
    for (j = 0; j < N; j++) printf(" %3d ", j);
    printf("\n");

    for (i = 0; i < N; i++) {
        printf(" %d | ", i);
        for (j = 0; j < N; j++) {
            if (table[i][j] == INF) {
                printf(" inf ");
            } else if (show_diff && table[i][j] != prev[i][j]) {
                printf(" %3d*", table[i][j]);
            } else {
                printf(" %3d ", table[i][j]);
            }
        }
        printf("\n");
    }
}
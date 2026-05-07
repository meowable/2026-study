#include <stdio.h>

#define N 7
#define INF 99999

extern int table[N][N];
extern int next_hop[N][N];
extern char names[N];

void print_paths(int src) {
    int j, cur, next;

    printf("\n[%c 기준 경로]\n", names[src]);

    for (j = 0; j < N; j++) {
        printf(" %c |", names[j]);

        if (table[src][j] == INF) {
            printf(" inf | ?\n");
        } else {
            printf(" %d | ", table[src][j]);

            cur = src;
            printf("%c", names[cur]);

            while (cur != j) {
                next = next_hop[cur][j];
                if (next == -1) {
                    printf(" → ?");
                    break;
                }
                printf(" → %c", names[next]);
                cur = next;
            }
            printf("\n");
        }
    }
}
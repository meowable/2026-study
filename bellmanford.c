#include <stdio.h>

#define N   7
#define INF 99999

int cost[N][N];
int table[N][N];
int next_hop[N][N];

int run_round() {
    int i, j, w;
    int changed = 0;
    int snapshot[N][N];

    // snapshot 저장
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            snapshot[i][j] = table[i][j];
        }
    }

    // 벨만-포드 핵심 로직
    for (i = 0; i < N; i++) {

        // 기존 경로 갱신
        for (j = 0; j < N; j++) {
            if (i == j) continue;

            int nh = next_hop[i][j];
            if (nh == -1) continue;

            int new_dist;
            if (cost[i][nh] == INF || snapshot[nh][j] == INF)
                new_dist = INF;
            else
                new_dist = cost[i][nh] + snapshot[nh][j];

            if (new_dist != table[i][j]) {
                table[i][j] = new_dist;
                if (new_dist == INF) next_hop[i][j] = -1;
                changed = 1;
            }
        }

        // 더 짧은 경로 탐색
        for (w = 0; w < N; w++) {
            if (cost[i][w] == INF || i == w) continue;

            for (j = 0; j < N; j++) {
                if (snapshot[w][j] == INF) continue;

                int new_dist = cost[i][w] + snapshot[w][j];
                if (new_dist < table[i][j]) {
                    table[i][j] = new_dist;
                    next_hop[i][j] = w;
                    changed = 1;
                }
            }
        }
    }

    return changed;
}
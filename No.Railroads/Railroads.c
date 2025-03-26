#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 105
#define MAX_TRAIN 1000
#define MAX_TIME 2400
#define INF -1

typedef struct {
    int to;
    short startTime, endTime;
} Edge;

Edge graph[MAX_CITIES][MAX_TRAIN];
int edgeCount[MAX_CITIES];  // 記錄每個城市的火車數量
short dist[MAX_TIME][MAX_CITIES]; // DP 陣列
char cityNames[MAX_CITIES][32];   // 存放城市名稱

int get_city_index(char *name, int city_count) {
    for (int i = 0; i < city_count; i++) {
        if (strcmp(cityNames[i], name) == 0) return i;
    }
    return -1;
}

void solve(char *name1, char *name2, int st, int ed, int st_time, int n) {
    int i, j, k;
    memset(dist, INF, sizeof(dist));

    // 初始點火車設定
    for (i = 0; i < edgeCount[st]; i++) {
        if (graph[st][i].startTime >= st_time) {
            int endT = graph[st][i].endTime;
            int to = graph[st][i].to;
            if (dist[endT][to] < graph[st][i].startTime) {
                dist[endT][to] = graph[st][i].startTime;
            }
        }
    }

    // 動態規劃 (DP) 方式計算最早抵達終點時間
    for (i = st_time; i < MAX_TIME; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF) continue;

            for (k = 0; k < edgeCount[j]; k++) {
                int startT = graph[j][k].startTime;
                int endT = graph[j][k].endTime;
                int to = graph[j][k].to;

                if (startT >= i && dist[endT][to] < dist[i][j]) {
                    dist[endT][to] = dist[i][j];
                }
            }
        }

        if (dist[i][ed] != INF) {
            printf("Departure %04d %s\n", dist[i][ed], name1);
            printf("Arrival   %04d %s\n", i, name2);
            return;
        }
    }

    puts("No connection");
}

int main() {
    int testcase, cases = 0;
    int N, T, M;
    int i, j, k;

    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%d", &N);
        
        for (i = 0; i < N; i++) {
            scanf("%s", cityNames[i]);
            edgeCount[i] = 0;
        }

        // 讀取火車時刻表
        scanf("%d", &T);
        int x, y, ptime, time, startTime;
        char cityName[32];
        
        while (T--) {
            scanf("%d", &M);
            for (i = 0; i < M; i++) {
                scanf("%d %s", &time, cityName);
                y = get_city_index(cityName, N);
                if (i > 0 && time >= ptime) {
                    graph[x][edgeCount[x]].to = y;
                    graph[x][edgeCount[x]].startTime = ptime;
                    graph[x][edgeCount[x]].endTime = time;
                    edgeCount[x]++;
                }
                x = y;
                ptime = time;
            }
        }

        char start[32], end[32];
        scanf("%d %s %s", &startTime, start, end);

        x = get_city_index(start, N);
        y = get_city_index(end, N);

        printf("Scenario %d\n", ++cases);
        solve(start, end, x, y, startTime, N);
        puts("");
    }

    return 0;
}

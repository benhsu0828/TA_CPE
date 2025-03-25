#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100
#define MAX_TRAINS 1000
#define MAX_STOPS 100
#define INF 999999

typedef struct {
    int time;
    char city[21];
} Stop;

typedef struct {
    int num_stops;
    Stop stops[MAX_STOPS];
} Train;

typedef struct {
    char name[21];
    int earliest_arrival;
    int latest_departure;
    int departure_time;
} City;

City cities[MAX_CITIES];
Train trains[MAX_TRAINS];
int num_cities, num_trains;

int find_city_index(char *name) {
    for (int i = 0; i < num_cities; i++) {
        if (strcmp(cities[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void dijkstra(int start_index, int start_time) {
    int dist[MAX_CITIES];
    int visited[MAX_CITIES] = {0};
    //初始化
    for (int i = 0; i < num_cities; i++) {
        dist[i] = INF;
        cities[i].departure_time = INF;
    }
    dist[start_index] = start_time;

    //找最短路徑
    for (int i = 0; i < num_cities; i++) {
        int min_dist = INF, u = -1;
        //找最小距離
        for (int j = 0; j < num_cities; j++) {
            if (!visited[j] && dist[j] < min_dist) {//沒有被訪問過且距離小於最小距離
                min_dist = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = 1;

        //更新最短路徑
        for (int t = 0; t < num_trains; t++) {
            //找到火車停靠站
            for (int s = 0; s < trains[t].num_stops - 1; s++) {
                int u_index = find_city_index(trains[t].stops[s].city);
                int v_index = find_city_index(trains[t].stops[s + 1].city);
                //如果是同一個城市且時間小於等於火車停靠時間且時間大於等於開始時間
                if (u_index == u && dist[u] <= trains[t].stops[s].time && trains[t].stops[s].time >= start_time) {
                    int arrival_time = trains[t].stops[s + 1].time;
                    if (arrival_time < dist[v_index] || (arrival_time == dist[v_index] && trains[t].stops[s].time > cities[v_index].departure_time)) {
                        dist[v_index] = arrival_time;
                        cities[v_index].latest_departure = trains[t].stops[s].time;
                        cities[v_index].departure_time = trains[t].stops[s].time;
                    }
                }
            }
        }
    }

    for (int i = 0; i < num_cities; i++) {
        cities[i].earliest_arrival = dist[i];
    }
}

int main() {
    int scenarios;
    scanf("%d", &scenarios);

    for (int scenario = 1; scenario <= scenarios; scenario++) {
        scanf("%d", &num_cities);
        //輸入城市名稱
        for (int i = 0; i < num_cities; i++) {
            scanf("%s", cities[i].name);
            cities[i].earliest_arrival = INF;
            cities[i].latest_departure = -1;
            cities[i].departure_time = INF;
        }

        scanf("%d", &num_trains);
        //輸入火車的停靠站
        for (int i = 0; i < num_trains; i++) {
            scanf("%d", &trains[i].num_stops);
            //輸入火車的停靠站時間和城市
            for (int j = 0; j < trains[i].num_stops; j++) {
                scanf("%d %s", &trains[i].stops[j].time, trains[i].stops[j].city);
            }
        }

        int start_time;
        char start_city[21], end_city[21];
        scanf("%d", &start_time);
        scanf("%s", start_city);
        scanf("%s", end_city);

        int start_index = find_city_index(start_city);
        int end_index = find_city_index(end_city);

        dijkstra(start_index, start_time);

        printf("Scenario %d\n", scenario);
        if (cities[end_index].earliest_arrival == INF) {
            printf("No connection\n");
        } else {
            printf("Departure %04d %s\n", cities[end_index].latest_departure, start_city);
            printf("Arrival   %04d %s\n", cities[end_index].earliest_arrival, end_city);
        }
        printf("\n");
    }

    return 0;
}
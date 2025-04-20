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
    // int latest_departure;
    // int departure_time;
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

void myAlgo(int start_index, int start_time) {
    //根據出發城市，先尋找最早出發的火車
    int earliest_train_index = -1;
    for(int i = 0; i < num_trains; i++) {
        if(strcmp(trains[i].stops[0].city, cities[start_index].name) == 0) {
            if(trains[i].stops[0].time >= start_time) {
                if(earliest_train_index == -1 || trains[i].stops[0].time < trains[earliest_train_index].stops[0].time) {
                    earliest_train_index = i;
                }
            }
        }
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
            // cities[i].latest_departure = -1;
            // cities[i].departure_time = INF;
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

        myAlgo(start_index, start_time);

        printf("Scenario %d\n", scenario);

        if (cities[end_index].earliest_arrival == INF) {
            printf("No connection\n");
        } else {
            // printf("Departure %04d %s\n", cities[end_index].latest_departure, start_city);
            // printf("Arrival   %04d %s\n", cities[end_index].earliest_arrival, end_city);
        }
        printf("\n");
    }

    return 0;
}
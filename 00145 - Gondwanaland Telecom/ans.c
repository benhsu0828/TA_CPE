#include <stdio.h>
#include <string.h>

typedef struct {
    char code;
    double rate[7];
} RatePlan;

int main() {
    RatePlan plans[] = {
        {'A', {0.02, 0.10, 0.06, 0.02, 0.10, 0.06, 0.02}},
        {'B', {0.05, 0.25, 0.15, 0.05, 0.25, 0.15, 0.05}},
        {'C', {0.13, 0.53, 0.33, 0.13, 0.53, 0.33, 0.13}},
        {'D', {0.17, 0.87, 0.47, 0.17, 0.87, 0.47, 0.17}},
        {'E', {0.30, 1.44, 0.80, 0.30, 1.44, 0.80, 0.30}},
    };
    int b[] = {480, 1080, 1320, 1920, 2520, 2760, 2880};//時間區間
    char step;
    int h1, m1, h2, m2;
    char phone[20];

    while (scanf(" %c", &step) == 1) {
        if (step == '#') break;

        scanf("%s %d %d %d %d", phone, &h1, &m1, &h2, &m2);

        double cost = 0.0;
        int Time[7] = {0};

        m1 += h1 * 60;
        m2 += h2 * 60;
        //若 m2 < m1，則代表橫跨一天，所以加上 24 小時
        if (m2 < m1) m2 += 24 * 60;

        // 找到對應方案的費率
        double *rate = NULL;
        for (int i = 0; i < 5; i++) {
            if (plans[i].code == step) {
                rate = plans[i].rate;
                break;
            }
        }

        if (rate == NULL) continue;

        for (int i = 0; i < 7; i++) {
            if (m1 <= b[i]) {
                if (m2 <= b[i]) {
                    Time[i] = m2 - m1;
                    cost += rate[i] * Time[i];
                    break;
                } else {
                    Time[i] = b[i] - m1;
                    cost += rate[i] * Time[i];
                    m1 = b[i];
                }
            }
        }

        printf("%10s%6d%6d%6d%3c%8.2f\n",
               phone,
               Time[1] + Time[4],
               Time[2] + Time[5],
               Time[0] + Time[3] + Time[6],
               step,
               cost);
    }

    return 0;
}

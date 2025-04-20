#include <stdio.h>

// 全域變數
int k, q1, q2;
int q1x, q1y, q2x, q2y, kx, ky;

// 檢查 c 是否在 a 和 b 之間（不含等號）
int is_between(int a, int b, int c) {
    if (b > a) {
        int temp = a;
        a = b;
        b = temp;
    }
    return (a > c && c > b);
}

// 是否為非法移動
int is_illegal_move() {
    if (k == q2 || q1 == q2)
        return 1;

    // 女王不是水平或垂直移動
    if ((q1 % 8 != q2 % 8) && (q1 / 8 != q2 / 8))
        return 1;

    // 國王阻擋在移動路徑上
    if ((is_between(q1x, q2x, kx) && q1y == ky) || (is_between(q1y, q2y, ky) && q1x == kx))
        return 1;

    return 0;
}

// 女王移動是否不允許（進入國王周圍一格）
int is_move_not_allow() {
    if ((k + 1 == q2 && q2 % 8 != 0) ||
        (k - 1 == q2 && q2 % 8 != 7) ||
        (k - 8 == q2) ||
        (k + 8 == q2))
        return 1;

    return 0;
}

// 移動後是否使國王無路可走
int is_stop() {
    if ((k == 0 && q2 == 9) ||
        (k == 7 && q2 == 14) ||
        (k == 56 && q2 == 49) ||
        (k == 63 && q2 == 54))
        return 1;

    return 0;
}

int main() {
    while (scanf("%d %d %d", &k, &q1, &q2) == 3) {
        q1x = q1 / 8;
        q1y = q1 % 8;
        q2x = q2 / 8;
        q2y = q2 % 8;
        kx = k / 8;
        ky = k % 8;

        if (k == q1)
            printf("Illegal state\n");
        else if (is_illegal_move())
            printf("Illegal move\n");
        else if (is_move_not_allow())
            printf("Move not allowed\n");
        else if (is_stop())
            printf("Stop\n");
        else
            printf("Continue\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000005

int a[MAXN];
int dq[MAXN];  // 用陣列實作 deque
int front, back;

void print_min(int n, int k) {
    front = back = 0;
    for (int i = 0; i < n; i++) {
        while (front < back && dq[front] <= i - k)
            front++;
        while (front < back && a[dq[back - 1]] > a[i])
            back--;
        dq[back++] = i;
        if (i == k - 1) printf("%d", a[dq[front]]);
        else if (i >= k) printf(" %d", a[dq[front]]);
    }
    if (k > n) printf("%d", a[dq[front]]);
    printf("\n");
}

void print_max(int n, int k) {
    front = back = 0;
    for (int i = 0; i < n; i++) {
        while (front < back && dq[front] <= i - k)
            front++;
        while (front < back && a[dq[back - 1]] < a[i])
            back--;
        dq[back++] = i;
        if (i == k - 1) printf("%d", a[dq[front]]);
        else if (i >= k) printf(" %d", a[dq[front]]);
    }
    if (k > n) printf("%d", a[dq[front]]);
    printf("\n");
}

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) == 2) {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        print_min(n, k);
        print_max(n, k);
    }
    return 0;
}

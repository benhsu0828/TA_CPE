#include <stdio.h>
#include <stdlib.h>

// 計算組合數 C(n, k) = n! / (k! * (n-k)!)
long long comb(int n, int k) {
    if (k > n - k) k = n - k; // C(n, k) == C(n, n-k)
    long long res = 1;
    for (int i = 0; i < k; i++) {
        res = res * (n - i) / (i + 1);
    }
    return res;
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        printf("%lld\n", comb(m + n - 2, m - 1));
    }
    return 0;
}
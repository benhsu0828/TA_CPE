#include <stdio.h>
#include <stdbool.h>

int main() {
    int loop;
    scanf("%d", &loop);

    for (int t = 1; t <= loop; t++) {
        int n;
        bool is_symmetric = true;
        scanf("%d", &n);

        long long matrix[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld", &matrix[i][j]);
            }
        }

        //檢查矩陣內元素是否與中心點對稱
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                //printf("%lld and %lld\n", matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
                if (matrix[i][j] != matrix[n - 1 - i][n - 1 - j] || matrix[i][j] < 0) {
                    is_symmetric = false;
                    break;
                }
            }
        }

        if (is_symmetric) {
            printf("Test #%d: Symmetric.\n", t);
        } else {
            printf("Test #%d: Non-symmetric.\n", t);
        }

    }
    return 0;
}

#include <stdio.h>

int bubbleSort(int arr[], int size) {
    int swaps = 0;
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交換相鄰元素
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}

int main() {
    int N, L;
    scanf("%d", &N);  // 讀取測資數量

    while (N--) {
        scanf("%d", &L);  // 讀取火車長度
        int train[50];    // 因題目限制 L ≤ 50，所以宣告大小為50的陣列

        // 讀取火車車廂順序
        for (int i = 0; i < L; i++) {
            scanf("%d", &train[i]);
        }

        // 計算最少交換次數並輸出結果
        int swaps = bubbleSort(train, L);
        printf("Optimal train swapping takes %d swaps.\n", swaps);
    }

    return 0;
}

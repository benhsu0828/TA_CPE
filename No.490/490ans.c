#include <stdio.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    char input[MAX_ROWS][MAX_COLS + 1]; // 儲存輸入的每一行文字
    int row_count = 0; // 計算輸入的行數
    int max_length = 0; // 記錄最長行的長度

    // 讀取輸入
    while (fgets(input[row_count], sizeof(input[row_count]), stdin)) {
        // 移除行尾的換行符號
        input[row_count][strcspn(input[row_count], "\n")] = '\0';
        int length = strlen(input[row_count]);
        if (length > max_length) {
            max_length = length;
        }
        row_count++;
        if (row_count >= MAX_ROWS) {
            break;
        }
    }

    // 輸出旋轉後的結果
    for (int col = 0; col < max_length; col++) {
        for (int row = row_count - 1; row >= 0; row--) {
            if (col < strlen(input[row])) {
                putchar(input[row][col]);
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}

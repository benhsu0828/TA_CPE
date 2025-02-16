#include <stdio.h>

int main() {
    int c;
    int isFirst = 1;  // 用來追蹤是否為第一個引號
    
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            // 如果是引號，根據是第一個還是第二個來輸出
            if (isFirst) {
                printf("``");
            } else {
                printf("''");
            }
            isFirst = !isFirst;  // 切換狀態
        } else {
            putchar(c);  // 輸出其他字元
        }
    }
    
    return 0;
}
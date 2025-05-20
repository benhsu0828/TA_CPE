#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[100001];
    while (scanf("%s", s) == 1 && strcmp(s, ".") != 0) {
        int N = strlen(s);
        int result = 1;  // 初始假設只有1個重複單元
        
        // 嘗試所有可能的重複單元長度
        for (int len = 1; len <= N/2; len++) {
            // 只考慮能整除總長度的長度
            if (N % len != 0) continue;
            
            bool is_repeating = true;
            
            // 檢查完整字串是否由長度為len的子字串重複構成
            for (int i = len; i < N; i++) {
                if (s[i] != s[i % len]) {
                    is_repeating = false;
                    break;
                }
            }
            
            // 如果是重複字串，計算重複次數
            if (is_repeating) {
                result = N / len;
                break;  // 找到最小重複單元，因為從小到大找
            }
        }
        
        printf("%d\n", result);
    }
    return 0;
}

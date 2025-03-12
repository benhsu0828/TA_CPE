#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char line[10005];
    
    // 逐行讀取輸入
    while (fgets(line, sizeof(line), stdin)) {
        size_t len = strlen(line);
        // 移除換行字元
        if (len > 0 && line[len-1] == '\n')
            line[len-1] = '\0';
        
        // 跳過空行
        if(line[0] == '\0') continue;
        
        int i = 0;
        // 跳過前導空白
        while(line[i] && isspace(line[i])) i++;
        // 若有符號，則跳過
        if(line[i] == '+' || line[i] == '-') {
            i++;
        }
        
        int max_digit = 0;
        unsigned long long sum = 0;  // 計算各位數和，數字可能較大但足夠存放 10000 位數每位最大 61 的總和
        
        // 從剩下的部分讀取各個數字
        for(; line[i] != '\0'; i++){
            char c = line[i];
            if (isspace(c)) continue;
            int value = 0;
            if(c >= '0' && c <= '9')
                value = c - '0';
            else if(c >= 'A' && c <= 'Z')
                value = c - 'A' + 10;
            else if(c >= 'a' && c <= 'z')
                value = c - 'a' + 36;
            // 更新最大 digit 值
            if(value > max_digit)
                max_digit = value;
            sum += value;
        }
        
        // 最小進位至少為 max_digit + 1，但也不能低於 2
        int min_base = (max_digit + 1 > 2 ? max_digit + 1 : 2);
        int answer = 0;
        
        // 遍歷所有可能的底數從 min_base 到 62
        for (int base = min_base; base <= 62; base++){
            int divisor = base - 1;  // 根據進位系統的性質：一個數在 base 下除以 (base-1) 的餘數等於各位數之和除以 (base-1) 的餘數
            if(sum % divisor == 0) { // 如果滿足條件，則找到最小底數
                answer = base;
                break;
            }
        }
        
        if(answer == 0)
            printf("such number is impossible!\n");
        else
            printf("%d\n", answer);
    }
    
    return 0;
}

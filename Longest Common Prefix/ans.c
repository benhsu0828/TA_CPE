#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "empty";
    
    char* prefix = (char*)malloc(201 * sizeof(char)); // 分配足夠空間存放結果
    strcpy(prefix, strs[0]); // 先將第一個字串作為基準
    
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0'; // 截斷不匹配的部分
        
        if (prefix[0] == '\0') { // 若沒有共同前綴
            free(prefix);
            return "empty";
        }
    }
    return prefix;
}

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        char strs[n][201];
        char* strPtrs[n];
        
        for (int i = 0; i < n; i++) {
            scanf("%s", strs[i]);
            strPtrs[i] = strs[i];
        }
        
        char* result = longestCommonPrefix(strPtrs, n);
        printf("%s\n", result);
        
        if (strcmp(result, "empty") != 0) {
            free(result);
        }
    }
    
    return 0;
}

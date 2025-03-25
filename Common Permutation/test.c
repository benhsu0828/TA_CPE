#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001

void find_common_permutation(char *a, char *b) {
    int count_a[26] = {0};
    int count_b[26] = {0};
    int i;

    // 計算每個字母在 a 和 b 中的出現次數
    for (i = 0; a[i] != '\0'; i++) {
        count_a[a[i] - 'a']++;
    }
    for (i = 0; b[i] != '\0'; i++) {
        count_b[b[i] - 'a']++;
    }

    // 找出共同的字母並按字母順序輸出
    for (i = 0; i < 26; i++) {
        int common_count = count_a[i] < count_b[i] ? count_a[i] : count_b[i];
        for (int j = 0; j < common_count; j++) {
            putchar('a' + i);
        }
    }
    putchar('\n');
}

int main() {
    char a[MAX_LEN];
    char b[MAX_LEN];

    while (fgets(a, MAX_LEN, stdin) && fgets(b, MAX_LEN, stdin)) {
        // 去掉換行符
        a[strcspn(a, "\n")] = '\0';
        b[strcspn(b, "\n")] = '\0';

        find_common_permutation(a, b);
    }

    return 0;
}
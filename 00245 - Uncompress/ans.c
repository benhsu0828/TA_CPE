#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 10000
#define MAX_WORDS 100000
#define MAX_WORD_LEN 51

char words[MAX_WORDS][MAX_WORD_LEN];
int word_count = 0;

// 將字串加到最後，若還沒出現過
void add_word(const char* word) {
    if (strlen(word) == 0) return;
    for (int i = 0; i < word_count; i++) {
        if (strcmp(words[i], word) == 0) return; // 已存在
    }
    if (word_count < MAX_WORDS) {
        strcpy(words[word_count++], word);
    }
}

// 移動 words[位置] 到最後（從後面數 num 位）
void move_word_to_end(int num) {
    if (num <= 0 || num > word_count) return;
    int index = word_count - num;
    char temp[MAX_WORD_LEN];
    strcpy(temp, words[index]);
    // 把之後的全部往前搬
    for (int i = index; i < word_count - 1; i++) {
        strcpy(words[i], words[i + 1]);
    }
    strcpy(words[word_count - 1], temp);
    printf("%s", temp);
}

int main() {
    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), stdin)) {
        if (strcmp(line, "0\n") == 0 || strcmp(line, "0\r\n") == 0) {
            break;
        }

        char temp[MAX_WORD_LEN] = "";
        int temp_len = 0;
        int num = 0;

        for (int i = 0; line[i] != '\0'; i++) {
            char c = line[i];

            if (isalpha(c)) {
                if (temp_len < MAX_WORD_LEN - 1)
                    temp[temp_len++] = c;
            } else if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else {
                temp[temp_len] = '\0';

                if (num) {
                    move_word_to_end(num);
                    num = 0;
                }

                if (temp_len > 0) {
                    add_word(temp);
                    printf("%s", temp);
                    temp_len = 0;
                }

                putchar(c);
            }
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STATES 10000
#define MAX_DEADENDS 500
#define CODE_LENGTH 6 // 包括 '\0'和'\n'
#define MAX_INPUT_LINE 1000 // 假設輸入的單行長度不會超過 1000

// 表示一個鎖的狀態
typedef struct {
    char code[CODE_LENGTH];
    int distance;
} State;

// 佇列結構
typedef struct {
    State *items;
    int front;
    int rear;
    int capacity;
} Queue;

// 初始化佇列
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->items = (State*)malloc(q->capacity * sizeof(State));
    return q;
}

// 判斷佇列是否為空
bool isEmpty(Queue* q) {
    return q->rear < q->front;
}

// 將元素加入佇列
void enqueue(Queue* q, State item) {
    if (q->rear == q->capacity - 1) {
        printf("Queue Overflow\n");
        return;
    }
    q->items[++q->rear] = item;
}

// 從佇列中移除並返回第一個元素
State dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        State emptyState = {"", -1};
        return emptyState;
    }
    return q->items[q->front++];
}

// 生成下一個可能的鎖狀態
void get_next_states(char current_code[CODE_LENGTH], State next_states[8]) {
    for (int i = 0; i < 4; i++) {
        // 向上轉動
        char up = current_code[i];
        if (up == '9') {
            up = '0';
        } else {
            up++;
        }
        strcpy(next_states[2 * i].code, current_code);
        next_states[2 * i].code[i] = up;
        next_states[2 * i].distance = -1;

        // 向下轉動
        char down = current_code[i];
        if (down == '0') {
            down = '9';
        } else {
            down--;
        }
        strcpy(next_states[2 * i + 1].code, current_code);
        next_states[2 * i + 1].code[i] = down;
        next_states[2 * i + 1].distance = -1;
    }
}

int openLock(char **deadends, int deadendsSize, char *target) {
    bool visited[MAX_STATES];
    for (int i = 0; i < MAX_STATES; i++) {
        visited[i] = false;
    }

    // 將 deadends 標記為已訪問
    for (int i = 0; i < deadendsSize; i++) {
        int code_int = atoi(deadends[i]);
        visited[code_int] = true;
    }

    Queue* q = createQueue(MAX_STATES);
    State start_state = {"0000", 0};
    enqueue(q, start_state);
    visited[0] = true; // 初始狀態 "0000" 的整數值是 0

    while (!isEmpty(q)) {
        State current_state = dequeue(q);
        if (strcmp(current_state.code, target) == 0) {
            free(q->items);
            free(q);
            return current_state.distance;
        }

        State next_states[8];
        get_next_states(current_state.code, next_states);

        for (int i = 0; i < 8; i++) {
            int next_code_int = atoi(next_states[i].code);
            if (!visited[next_code_int]) {
                visited[next_code_int] = true;
                next_states[i].distance = current_state.distance + 1;
                enqueue(q, next_states[i]);
            }
        }
    }

    free(q->items);
    free(q);
    return -1; // 無法到達目標狀態
}

int main() {
    char deadends_str[MAX_INPUT_LINE];
    char target_str[CODE_LENGTH];
    char *deadends[MAX_DEADENDS];
    char temp_str[MAX_INPUT_LINE];  // 新增臨時字串來儲存原始輸入

    // 持續讀取輸入直到檔案結束
    while (1) {
        // 讀取第一行 deadends
        if (fgets(deadends_str, sizeof(deadends_str), stdin) == NULL) {
            break;  // 如果讀取失敗，表示已到檔案結尾
        }
        deadends_str[strcspn(deadends_str, "\n")] = 0;  // 移除換行符

        // 讀取第二行 target
        if (fgets(target_str, sizeof(target_str), stdin) == NULL) {
            break;  // 如果讀取失敗，表示已到檔案結尾
        }
        target_str[strcspn(target_str, "\n")] = 0;  // 移除換行符

        // 處理 deadends
        int deadendsSize = 0;
        char *token = strtok(deadends_str, ",");  // 使用臨時字串進行分割
        while (token != NULL && deadendsSize < MAX_DEADENDS) {
            deadends[deadendsSize++] = token;
            token = strtok(NULL, ",");
        }

        // 計算並輸出結果
        int result = openLock(deadends, deadendsSize, target_str);
        printf("%d\n", result);
    }

    return 0;
}
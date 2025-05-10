#include <stdio.h>
#define MAX_NAME 10
#define MAX_QUEUE 100

typedef struct {
    char idol;
    int tickets;
    char name[MAX_NAME];
    int served;     // 標記是否已被服務
} Fan;

void processQueue(Fan* fans, int fanCount, int totalTime) {
    int currentTime = 0;
    int idolBusy[3] = {0, 0, 0};  // 記錄每個偶像的忙碌時間
    char idols[] = {'A', 'K', 'B'}; // 定義偶像名稱陣列
    
    while (currentTime < totalTime) {
        // 檢查每個粉絲
        for (int i = 0; i < fanCount; i++) {
            if (!fans[i].served) {  // 如果粉絲還沒被服務
                // 找出該粉絲要找的偶像編號
                int idolIndex;
                for (idolIndex = 0; idolIndex < 3; idolIndex++) {
                    if (fans[i].idol == idols[idolIndex]) break;
                }
                
                // 檢查該偶像是否有空且時間是否足夠
                if (idolBusy[idolIndex] <= currentTime) {
                    if(currentTime + fans[i].tickets > totalTime){
                        idolBusy[idolIndex] = totalTime + 1;
                        fans[i].tickets = fans[i].tickets - (totalTime - currentTime);  // 調整票數以符合剩餘時間
                    }else{
                        fans[i].served = 1;  // 標記為已服務
                        idolBusy[idolIndex] = currentTime + fans[i].tickets;
                    }
                    
                    break;  // 每分鐘只服務一位粉絲
                }
            }
        }
        currentTime++;
    }
    
    // 輸出結果
    for (int i = 0; i < 3; i++) {
        printf("%c:", idols[i]);
        int hasUnserved = 0;
        for (int j = 0; j < fanCount; j++) {
            if (fans[j].idol == idols[i] && !fans[j].served) {
                printf(" %s", fans[j].name);
                hasUnserved = 1;
            }
        }
        if (!hasUnserved) {
            printf(" ");
        }
        if(i == 3){
            printf(".");
        }else{
            printf(".\n");
        }
    }
}

int main(void) {
    int totalTime = 0, fanCount = 0;
    scanf("%d %d", &totalTime, &fanCount);
    getchar();
    
    Fan fans[fanCount];
    for (int i = 0; i < fanCount; i++) {
        fans[i].served = 0;  // 初始化為未服務
        scanf("%c %d %s", &fans[i].idol, &fans[i].tickets, fans[i].name);
        getchar();
    }
    
    processQueue(fans, fanCount, totalTime);
    return 0;
}
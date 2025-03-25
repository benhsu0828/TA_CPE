#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNTRIES 2000
#define MAX_LEN 75

int main(void) {
    char country[MAX_COUNTRIES][MAX_LEN];//國家名稱
    int countrycount[MAX_COUNTRIES] = {0};//國家女生計數
    int count = 0;//國家總數量
    int n;

    scanf("%d", &n);
    getchar(); // 吃掉換行符

    for (int i = 0; i < n; i++) {
        char line[MAX_LEN];
        fgets(line, MAX_LEN, stdin);
		// 去掉換行符
        line[strcspn(line, "\n")] = '\0';

        // 分割字串
		char *countryPtr = strtok(line, " ");
        int found = 0;

        for (int j = 0; j < count; j++) {
			// 如果找到國家名稱，則增加該國家的計數
            if (strcmp(country[j], countryPtr) == 0) {
                countrycount[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
			// 如果找不到國家名稱，則新增一個國家
            strcpy(country[count], countryPtr);
            countrycount[count]++;
            count++;
        }
    }

    // 按字母順序排序
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(country[j], country[j + 1]) > 0) {
                int tempCount = countrycount[j];
                countrycount[j] = countrycount[j + 1];
                countrycount[j + 1] = tempCount;

                char tempCountry[MAX_LEN];
                strcpy(tempCountry, country[j]);
                strcpy(country[j], country[j + 1]);
                strcpy(country[j + 1], tempCountry);
            }
        }
    }

    // 輸出結果
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", country[i], countrycount[i]);
    }

    return 0;
}
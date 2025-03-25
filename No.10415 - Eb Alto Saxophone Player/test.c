#include <stdio.h>
#include <string.h>

int main(void) {
    int mp[128][11] = {0};

    // 定義每個音符對應的手指按鍵
    mp['c'][2] = 1; mp['c'][3] = 1; mp['c'][4] = 1; mp['c'][7] = 1; mp['c'][8] = 1; mp['c'][9] = 1; mp['c'][10] = 1;
    mp['d'][2] = 1; mp['d'][3] = 1; mp['d'][4] = 1; mp['d'][7] = 1; mp['d'][8] = 1; mp['d'][9] = 1;
    mp['e'][2] = 1; mp['e'][3] = 1; mp['e'][4] = 1; mp['e'][7] = 1; mp['e'][8] = 1;
    mp['f'][2] = 1; mp['f'][3] = 1; mp['f'][4] = 1; mp['f'][7] = 1;
    mp['g'][2] = 1; mp['g'][3] = 1; mp['g'][4] = 1;
    mp['a'][2] = 1; mp['a'][3] = 1;
    mp['b'][2] = 1;
    mp['C'][3] = 1;
    mp['D'][1] = 1; mp['D'][2] = 1; mp['D'][3] = 1; mp['D'][4] = 1; mp['D'][7] = 1; mp['D'][8] = 1; mp['D'][9] = 1;
    mp['E'][1] = 1; mp['E'][2] = 1; mp['E'][3] = 1; mp['E'][4] = 1; mp['E'][7] = 1; mp['E'][8] = 1;
    mp['F'][1] = 1; mp['F'][2] = 1; mp['F'][3] = 1; mp['F'][4] = 1; mp['F'][7] = 1;
    mp['G'][1] = 1; mp['G'][2] = 1; mp['G'][3] = 1; mp['G'][4] = 1;
    mp['A'][1] = 1; mp['A'][2] = 1; mp['A'][3] = 1;
    mp['B'][1] = 1; mp['B'][2] = 1;

    int t;
    char s[201];

    scanf("%d", &t);
    getchar();//吃掉換行符

    while (t--) {
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0';

        int count[11] = {0};
        int a[11] = {0};

        for (int i = 0; s[i] != '\0'; i++) {
            for (int j = 1; j <= 10; j++) {
                if (mp[s[i]][j]) {
                    if (!a[j]) {
                        a[j] = 1;
                        count[j]++;
                    }
                } else {
                    a[j] = 0;
                }
            }
        }

        for (int i = 1; i < 10; i++) {
            printf("%d ", count[i]);
        }
        printf("%d\n", count[10]);

    }

    return 0;
}
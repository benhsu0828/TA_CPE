#include <stdio.h>
#include <string.h>

int main(void){
    int mp[128][11] = {0};

    mp['c'][0] = 0; mp['c'][1] = 0; mp['c'][2] = 1; mp['c'][3] = 1; mp['c'][4] = 1;
    mp['c'][5] = 0; mp['c'][6] = 0; mp['c'][7] = 1; mp['c'][8] = 1; mp['c'][9] = 1;
    mp['c'][10] = 1;

    mp['d'][0] = 0; mp['d'][1] = 0; mp['d'][2] = 1; mp['d'][3] = 1; mp['d'][4] = 1;
    mp['d'][5] = 0; mp['d'][6] = 0; mp['d'][7] = 1; mp['d'][8] = 1; mp['d'][9] = 1;
    mp['d'][10] = 0;

    mp['e'][0] = 0; mp['e'][1] = 0; mp['e'][2] = 1; mp['e'][3] = 1; mp['e'][4] = 1;
    mp['e'][5] = 0; mp['e'][6] = 0; mp['e'][7] = 1; mp['e'][8] = 1; mp['e'][9] = 0;
    mp['e'][10] = 0;

    mp['f'][0] = 0; mp['f'][1] = 0; mp['f'][2] = 1; mp['f'][3] = 1; mp['f'][4] = 1;
    mp['f'][5] = 0; mp['f'][6] = 0; mp['f'][7] = 1; mp['f'][8] = 0; mp['f'][9] = 0;
    mp['f'][10] = 0;

    mp['g'][0] = 0; mp['g'][1] = 0; mp['g'][2] = 1; mp['g'][3] = 1; mp['g'][4] = 1;
    mp['g'][5] = 0; mp['g'][6] = 0; mp['g'][7] = 0; mp['g'][8] = 0; mp['g'][9] = 0;
    mp['g'][10] = 0;

    mp['a'][0] = 0; mp['a'][1] = 0; mp['a'][2] = 1; mp['a'][3] = 1; mp['a'][4] = 0;
    mp['a'][5] = 0; mp['a'][6] = 0; mp['a'][7] = 0; mp['a'][8] = 0; mp['a'][9] = 0;
    mp['a'][10] = 0;

    mp['b'][0] = 0; mp['b'][1] = 0; mp['b'][2] = 1; mp['b'][3] = 0; mp['b'][4] = 0;
    mp['b'][5] = 0; mp['b'][6] = 0; mp['b'][7] = 0; mp['b'][8] = 0; mp['b'][9] = 0;
    mp['b'][10] = 0;

    mp['C'][0] = 0; mp['C'][1] = 0; mp['C'][2] = 0; mp['C'][3] = 1; mp['C'][4] = 0;
    mp['C'][5] = 0; mp['C'][6] = 0; mp['C'][7] = 0; mp['C'][8] = 0; mp['C'][9] = 0;
    mp['C'][10] = 0;

    mp['D'][0] = 0; mp['D'][1] = 1; mp['D'][2] = 1; mp['D'][3] = 1; mp['D'][4] = 1;
    mp['D'][5] = 0; mp['D'][6] = 0; mp['D'][7] = 1; mp['D'][8] = 1; mp['D'][9] = 1;
    mp['D'][10] = 0;

    mp['E'][0] = 0; mp['E'][1] = 1; mp['E'][2] = 1; mp['E'][3] = 1; mp['E'][4] = 1;
    mp['E'][5] = 0; mp['E'][6] = 0; mp['E'][7] = 1; mp['E'][8] = 1; mp['E'][9] = 0;
    mp['E'][10] = 0;

    mp['F'][0] = 0; mp['F'][1] = 1; mp['F'][2] = 1; mp['F'][3] = 1; mp['F'][4] = 1;
    mp['F'][5] = 0; mp['F'][6] = 0; mp['F'][7] = 1; mp['F'][8] = 0; mp['F'][9] = 0;
    mp['F'][10] = 0;

    mp['G'][0] = 0; mp['G'][1] = 1; mp['G'][2] = 1; mp['G'][3] = 1; mp['G'][4] = 1;
    mp['G'][5] = 0; mp['G'][6] = 0; mp['G'][7] = 0; mp['G'][8] = 0; mp['G'][9] = 0;
    mp['G'][10] = 0;

    int t;
    char s[1010];
    
    scanf("%d", &t);
    getchar();

    while(t--){
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0';

        int count[11] = {0};
        int a[11] = {0};

        for(int i = 0; s[i] != '\0'; i++){
            for(int j = 1; j <= 10; j++){
                if(mp[s[i]][j]){
                    if(a[j]) continue;
                    else{
                        
                        a[j] = 1;
                        count[j]++;
                        printf("%c j:%d %d\n",s[i],j,count[j]);
                    }
                } else{
                    a[j] = 0;
                    printf("%c j:%d %d\n",s[i],j,count[j]);
                }
            }
        }

        for(int i = 1; i <= 10; i++){
            printf("%d ", count[i]);
        }
        printf("\n");
    }

    return 0;
}
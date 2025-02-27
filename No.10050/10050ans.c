#include<stdio.h>
#include<string.h>

int main(){
    int loop;
    scanf("%d", &loop);
    while(loop--){
        int days = 0;
        int num = 0;
        scanf("%d %d", &days, &num);
        int party[num];
        for(int i = 0; i < num; i++){
            scanf("%d", &party[i]);
        }
        int hartal = 0;
        for(int i = 1; i <= days; i++){
            //0 is saturday, 1 is sunday 6 is friday
            if(i % 7 == 6 || i % 7 == 0){
                continue;
            }
            for(int j = 0; j < num; j++){
                if(i % party[j] == 0){
                    hartal++;
                    break;
                }
            }
        }
        printf("%d\n", hartal);
    }
}
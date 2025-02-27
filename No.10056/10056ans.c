#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main(){
    int loop;
    scanf("%d", &loop);
    for(int i = 0; i < loop; i++){
        int n;
        scanf("%d", &n);
        double p;
        scanf("%lf", &p);
        int win_player;
        scanf("%d", &win_player);
        if(p == 0){
            printf("0.0000\n");
        }else{
            //第win_player位玩家獲勝的機率，並且推廣到無窮回合
            printf("%.4f\n", p * pow(1 - p, win_player - 1) / (1 - pow(1 - p, n)));
        }
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    char str[1000];
    while(fgets(str,1000,stdin)!=NULL){
        int count[128]={0};
        int ascii_no[128]={0};
        for(int i=0;i<128;i++){
            ascii_no[i]=i;
        }
        for(int i=0;str[i]!='\0'&&str[i]!='\n';i++){
            count[str[i]]++;
        }
        //依照出現的次數由小到大輸出。如果有2個以上的字元有相同的次數，則ASCII值較大的先輸出。
        for(int i=1;i<128;i++){
            for(int j=127;j>=i;j--){
                if(count[j]>count[j-1]){
                    int tmp1=count[j];
                    int tmp2=ascii_no[j];
                    count[j]=count[j-1];
                    count[j-1]=tmp1;
                    ascii_no[j]=ascii_no[j-1];
                    ascii_no[j-1]=tmp2;
                }
            }
        }

        for(int i=127;i>=0;i--){
            if(count[i]>0){
                printf("%d %d\n",ascii_no[i],count[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
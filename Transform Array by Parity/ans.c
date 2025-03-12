#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int main(){
    int arr[100]={-1};
    int count=0;
    int count_even=0;
    int count_odd=0;

    for(int i=0;i<100;i++){
        scanf("%d",&arr[i]);
        if(arr[i]==0){
            arr[i]=-1;
            break;
        }
        count++;
    }
    for(int i=0;i<count;i++){
        if(arr[i]%2==0){
            count_even++;
        }else{
            count_odd++;
        }
    }
    //printf("even=%d,odd=%d\n",count_even,count_odd);
    for(int i=0;i<count_even;i++){
        printf("0");
        if(count_odd!=0||i!=count_even-1){
            printf(",");
        }
    }
    for(int i=0;i<count_odd;i++){
        printf("1");
        if(i!=count_odd-1){
            printf(",");
        }
    }
    printf("\n");
    return 0;
}
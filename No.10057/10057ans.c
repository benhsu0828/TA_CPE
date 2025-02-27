#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Exchange(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
   }
   
void QSORT(int *nums, int left, int right){  
    if(left>=right) return; //終止條件
    int l=left+1; //左
    int r=right; //右
    int key=nums[left];
    while(1){
    while(l<=right){
        if(nums[l]>key) break;
        l++;
    }
    while(r>left){
        if(nums[r]<key) break;
        r--;
    }
    if(l>r) break;
    Exchange(&nums[l],&nums[r]); 
    }
    //key 和 相遇的值 互換
    Exchange(&nums[left],&nums[r]);
    //分小組繼續進行
    QSORT(nums,left,r-1);
    QSORT(nums,r+1,right);
}

int main(){
    int loop;
    while(scanf("%d",&loop)!=EOF){
        if(loop==0){
            break;
        }

        int *arr = (int*)malloc(sizeof(int)*loop);
        for(int i=0;i<loop;i++){
            scanf("%d",&arr[i]);
        }
        // //排序並且取得中位數
        // for(int i = 0;i<loop;i++){
        //     for(int j=0;j<loop-1;j++){
        //         if(arr[j]>arr[j+1]){
        //             int temp = arr[j];
        //             arr[j] = arr[j+1];
        //             arr[j+1] = temp;
        //         }
        //     }
        // }
        QSORT(arr,0,loop-1);
        //計算有多少數字和中位數差值最小
        int count1 = 0;
        int count2 = 0;
        if(loop%2==0 && arr[loop/2-1]!=arr[loop/2]){
            for(int i=0;i<loop;i++){
                if(arr[i]-arr[loop/2]==0){
                    count1++;
                }
                if(arr[i]-arr[loop/2-1]==0){
                    count2++;
                }
            }
        }else{
            for(int i=0;i<loop;i++){
                if(arr[i]-arr[loop/2]==0){
                    count1++;
                }
            }
        }
        int count = count1 + count2;
        //輸出，如果loop為偶數則輸出2
        if(loop%2==1){
            printf("%d %d 1\n",arr[loop/2],count);
        }else{
            int tmp_count = 1;
            for(int i = arr[loop/2-1];i<arr[loop/2];i++){
                tmp_count++;
            }
            printf("%d %d %d\n",arr[loop/2-1],count,tmp_count);
        }
    }
}
#include <stdio.h>

int abc(int a,int count){
    count++;
    if(a==1){
        return count;
    }
    else if(a%2==0){
        return abc(a/2,count);
    }
    else if(a%2==1&&a>1){
        return abc(3 * a + 1,count);
    }

}

int main(){
    int i, j,a,b;

    while((scanf("%d %d", &i, &j))!=EOF){
        int max = 0;
        if(j<i){
            a = j;
            b = i;
        }else{
            a = i;
            b = j;
        }

        for(int k=a;k<=b;k++){

            if(abc(k,0)>max){
                max = abc(k, 0);
            }
        }
        printf("%d %d %d\n",i,j,max);
    }
}
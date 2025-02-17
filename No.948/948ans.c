#include<stdio.h>

void fib2(int num1,int num2,int stop){
    if(num2 == 1 && stop == 0){
        printf("0");
    }else if(stop == 0){
        printf("0");
        fib2(num2 - num1,num1,stop);
    }else if(num2 == stop){
        printf("1");
        if(num1-num2!=0) fib2(num2 - num1,num1,stop - num2);
    }else if(num2 > stop){
        printf("0");
        fib2(num2 - num1,num1,stop);
    }else{
        printf("1");
        fib2(num2 - num1,num1,stop - num2);
    }
} 
//4 234 1 121 0 111 1
//3 233 1 120 0 110 0
//1 121 0 111 1
void fib(int num1,int num2,int stop){
    if(stop == 1){
        printf("1");
    }else if(num1+num2>stop){
        fib2(num1,num2,stop);
    }else{
        fib(num2,num1+num2,stop);
    }
}
//20 7 2 121
//1	2 3	5 8	13 21

int main (){
    int loop = 0;
    scanf("%d",&loop);
    for(int i = 0;i<loop;i++){
        int dec_in = 0;
        scanf("%d", &dec_in);
        printf("%d = ", dec_in);
        fib(1,2,dec_in);
        printf(" (fib)\n");
    }

}
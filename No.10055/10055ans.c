#include<stdio.h>
#include<string.h>

int main(){
    unsigned long long num1, num2;
    while(scanf("%llu %llu", &num1, &num2) != EOF){
        printf("%llu\n", num1 > num2 ? num1 - num2 : num2 - num1);
    }
    return 0;
}
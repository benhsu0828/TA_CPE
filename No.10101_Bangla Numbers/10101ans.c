#include <stdio.h> 

void numfunction(long long n) /// 運算式
{
    if (n / 10000000)
    {
        numfunction(n / 10000000); /// 由於kuit可能不只小於10000000，所以要一直呼叫在遞回
        printf(" kuti");

        n %= 10000000;
        if (n > 0)
            printf(" "); /// 一切看到這個印空白的都是為了格式= =
    }
    if (n / 100000)
    {
        printf("%lld lakh", n / 100000);
        n %= 100000;
        if (n > 0)
            printf(" ");
    }
    if (n / 1000)
    {
        printf("%lld hajar", n / 1000);
        n %= 1000;
        if (n > 0)
            printf(" ");
    }
    if (n / 100)
    {
        printf("%lld shata", n / 100);
        n %= 100;
        if (n > 0)
            printf(" ");
    }
    if (n != 0)
        printf("%lld", n);
}

int main()
{
    long long n;                     /// 由於數字會很大要用long long讀
    int count = 1;                   /// 代表執行了起始值也代表前面表題的起始值
    while (scanf("%lld", &n) != EOF) /// 讀值讀到沒有為止才停止
    {
        printf("%4d. ", count); /// 印題號
        if (n == 0)
            printf("%d", n);
        else
            numfunction(n);
        printf("\n"); // 最後每題的換行
        count++;      /// 執行完一次後便讓標題+1
    }
}
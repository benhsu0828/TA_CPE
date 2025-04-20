#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int solve(int x, int *arr, int n){
    long long int total=0; 
    for(int i=0; i<n-1; i++){
        total = total * x + arr[i] * (n - i - 1);
    }
    return total;
}

int main(){
    int x, coe[1000000];
    while(scanf("%d", &x) != EOF){
        char line[1000000];
        getchar();
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = 0; 
        int count=0;
        char *token = strtok(line, " ");
        while(token != NULL){
            coe[count++] = atoi(token);
            token = strtok(NULL, " ");
        }
        printf("%lld\n", solve(x, coe, count));
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
	
	int x;
	while(scanf("%d", &x) != EOF){
		getchar();
		char exp[100];
		fgets(exp, 100, stdin);
		exp[strcspn(exp, "\n")] = '\0';
		char *token = strtok(exp, " ");
		int count = 0;
		int intexp[100];
		while(token != NULL){
			intexp[count++] = strtol(token, NULL, 10);
			token = strtok(NULL, " ");
		}
		int sum = 0, e = 1;
		for(int i = count-2; i>=0; i--){
			sum = sum + e*pow(x, e-1);
			e++;
		}
		printf("%d\n", sum);
	}
}
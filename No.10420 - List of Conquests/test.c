#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 75

int main(void){
	char country[2000][77];
	int a;
	int count = 0;
	int countrycount[2000] = {0};
	scanf("%d", &a);
	getchar();
	
	for (int i = 0 ; i < a ; i++)
	{
		char female[max];
		int n = 0;
		fgets(female, max, stdin);
		female[strcspn(female, "\n")] = '\0';
		
		char *countryPtr = strtok (female, " ");	
		if(count == 0)
		{
			countrycount[count] += 1;
			strcpy (country[count], countryPtr);
			count ++;
		}
		else
		{
			for(int j = 0 ; j < count ; j++)
			{
				if(strcmp(country[j], countryPtr) == 0)
				{
					countrycount[j] += 1;
					n = 1;
					break;
				}
			}
			if(n == 0)
			{
				countrycount[count] += 1;
				strcpy (country[count], countryPtr); 
				count ++;
			}
			
		}
	} 
	for(int i = 0 ; i < count - 1 ; i++)
	{
		for(int j = 0 ; j < count - i - 1 ; j++)
		{
			if(strncmp(country[j], country[j+1], 1) > 0)
			{
				int temp = countrycount[j];
				countrycount[j] = countrycount[j+1];
				countrycount[j+1] = temp;
				
				char tempchar[max];
				strcpy(tempchar, country[j]);
				strcpy(country[j], country[j+1]);
				strcpy(country[j+1], tempchar);
			}
		}
	}
	
	for(int m = 0 ; m < count ; m++)
		{
			printf("%s %d\n", country[m], countrycount[m]);
		}
}
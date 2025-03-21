#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){

    char s[999]= {0};
    char table[ ] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
   
	while(fgets(s, sizeof(s), stdin)!=NULL){
	
	for(int i=0;i<strlen(s);i++){
		if(isupper(s[i])){
			s[i]=tolower(s[i]);
		}
	
	}
	
    for(int i=0;i<strlen(s);i++){
    		if(isspace(s[i])){
        		printf(" ");
			}
        for(int j=0;j<strlen(table);j++){
        
    		if(s[i] == table[j]){
        	printf("%c", table[j - 2]);
        	
        	break;
    		}
		}
    }
    printf("\n");
}	

    return 0;
}
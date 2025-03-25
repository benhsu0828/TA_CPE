#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char c;
	char s[] ="1234567890-="
			"qwertyuiop[]\\"
			"asdfghjkl;'"
			"zxcvbnm,./";
	while((c = getchar()) != EOF){
		c = tolower(c);
		char *p =strchr(s, c);
		putchar(p ? *(p-2) : c);
	}
	return 0;
}
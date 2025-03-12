#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int main(){
    char s[100];
    fgets(s,1000,stdin);
    int n = strlen(s);
    //先讓所有字母變成小寫
    for(int i =0;i<n;i++){
        s[i] = tolower(s[i]);
    }
    //再依序把字母變成大寫
    for(int i =0;i<n-1;i++){
        if(s[i] == ' '){
            continue;
        }
        s[i] = toupper(s[i]);
        printf("%s", s);
        s[i] = tolower(s[i]);
    }

}
#include<stdio.h>
#include<string.h>

int main(){
    char str1[1000] = {0};
    char str2[1000] = {0};


    while (gets(str1))
    {
        gets(str2);
        int arr1[26] = {0};
        int arr2[26] = {0};

        for (int i = 0; i < strlen(str1); i++)
        {
            arr1[str1[i] - 'a']++;
        }
        for (int i = 0; i < strlen(str2); i++)
        {
            arr1[str2[i] - 'a']++;
        }
    int min = 0;
        

        for(int i = 0; i < 26; i++){
            if(arr1[i] && arr2[i]){
                if(str1[i] <= str2[i]){
                min = arr1[i];
            }else{
                min = arr2[i];
            }


            for(int j = 0; j < min; j++){
                printf("%c",i + 'a');
            }
            }
        }
        printf("\n");

    }
    return 0;
}
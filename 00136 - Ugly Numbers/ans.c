#include<stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int a, count = 0, temp = 0;
    temp = 1;
    FILE *infp = fopen("input.txt", "r");
    FILE *outfp = fopen("output.txt", "w");
    if (infp == NULL)
    {
        //printf("Error opening input file.\n");
        return 1;
    }
    if (outfp == NULL)
    {
        //printf("Error opening output file.\n");
        fclose(infp);
        return 1;
    }
    // Read the first line from the input file
    char line[100];
    fgets(line, sizeof(line), infp);
    while (count <= 1500)
    {
        a = temp;
        while (a % 2 == 0)
        {
            a = a / 2;
        }
        while (a % 3 == 0)
        {
            a = a / 3;
        }
        while (a % 5 == 0)
        {
            a = a / 5;
        }
        if (a == 1)
        {
            count++;
            if (count == 1500)
            {
                break;
            }
        }
        temp++;
    }
    fprintf(outfp, "The 1500'th ugly number is %d.", temp);
    fclose(infp);
    fclose(outfp);
    return 0;
}
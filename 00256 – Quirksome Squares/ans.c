#include <stdio.h>
#include <math.h>

#define MAX_NUM 10000

int main() {
    int quirkNumbers[MAX_NUM];
    int size = 0;

    // 預先儲存 n^2
    for (int n = 0; n < MAX_NUM; ++n) {
        quirkNumbers[size++] = n * n;
    }
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        //printf("Error opening input file.\n");
        return 1;
    }
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        //printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }
    int d;
    //while (scanf("%d", &d) == 1) {
    while (fscanf(inputFile, "%d", &d) == 1) {
        int limit = (int)pow(10.0, d);
        int half = d / 2;
        int upper = (int)pow(10.0, half);

        for (int i = 0; i < size; ++i) {
            if (quirkNumbers[i] >= limit) {
                break;
            }
            int U = quirkNumbers[i] / upper;
            int L = quirkNumbers[i] % upper;
            if ((U + L) * (U + L) == quirkNumbers[i]) {
                //printf("%0*d\n", d, quirkNumbers[i]);  // 前面補0
                fprintf(outputFile, "%0*d\n", d, quirkNumbers[i]);  // 前面補0
            }
        }
    }

    return 0;
}

#include <stdio.h>

int main() {
	int high[10005] = {0};
    int Li, Hi, Ri;
    int min = 10000, max = 0;
	FILE *cfPtr;
	FILE *dfPtr;
	cfPtr = fopen("input.txt","r");
	dfPtr = fopen("output.txt","w");

    while (fscanf(cfPtr,"%d %d %d", &Li, &Hi, &Ri)==3) {
    	
        if (Li < min) min = Li;
        if (Ri > max) max = Ri;
        for (int i = Li; i < Ri; i++) {
            if (Hi > high[i]) {
                high[i] = Hi;
            }
        }
    }

    Hi = -1;
    for (int i = min; i <= max; i++) {
        if (high[i] != Hi) {
            fprintf(dfPtr,"%d %d ", i, high[i]);
            Hi = high[i];
        }
    }
    fprintf(dfPtr,"\n");

    return 0;
}
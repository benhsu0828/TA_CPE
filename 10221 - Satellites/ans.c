#include <stdio.h>
#include <math.h>

int main() {
	
	FILE *fp1,*fp2;
	fp1 = fopen("input.txt","r");
	fp2 = fopen("output.txt","w");		
	
    double s, a;
    const double pi = acos(-1);
    char cmd[20];
    while(fscanf(fp1,"%lf %lf", &s, &a) == 2) {
        fscanf(fp1,"%s", cmd);
        if(cmd[0] == 'm')
            a /= 60;
        if(a>360)
          a = fmod(a,360);
        if(a > 180)
            a = 360-a;
        s += 6440;
        fprintf(fp2,"%.6lf %.6lf\n", s*a/180*pi, 2*sqrt(s*s-pow(s*cos(a/360*pi), 2)));
    }
    
    fclose(fp1);
	fclose(fp2);
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 質數判斷函數
int is_prime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i ++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int x;
    
    while (scanf("%d", &x) != EOF) {
        if (is_prime(x)) {
            printf("Prime\n");
        } else {
            printf("Not prime\n");
        }
    }
    
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 質數判斷函數
int is_prime(int x) {
    if (x < 2) return 0;
    if (x == 2 || x == 3) return 1;
    if (x % 2 == 0 || x % 3 == 0) return 0;
    
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
    int x;
    
    while (scanf("%d", &x) != EOF) {
        if (is_prime(x)) {
            printf("Prime\n");
        } else {
            printf("Not prime\n");
        }
    }
    
    return 0;
}

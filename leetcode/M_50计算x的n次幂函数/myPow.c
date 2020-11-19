#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n);


int main(int argc, char* argv[]) {
    

    double x = atof(argv[1]);
    int n = atoi(argv[argc-1]);
    
    printf("求%f的%d次幂.\n", x, n);
    printf("答案为：%f^%d=%f\n", x, n, myPow(x, n));
    return 0;
}


double myPow(double x, int n) {
    if (x == 1 || x == 0) {
        return x;
    }
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 1 / myPow(x, -n);
    }

    double tmp = myPow(x, n / 2);
    if (n % 2) {
        return tmp * tmp * x;
    } else {
        return tmp * tmp;
    }
}

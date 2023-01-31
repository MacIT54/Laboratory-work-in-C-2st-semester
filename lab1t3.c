#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define pi 3.14159265

double fac(double n) {
    if (n <= 1) {
        return 1;
    } 
    return n * fac(n - 1);
}

double cosinus(double x) {   
    float an = 1.0;
    float result = an;
    int n = 1;
    while (fabs(an) >= 0.0001) { 
        an *= -x*x/(2.*n*(2*n-1));
        result += an;
        n++;
    } 
    return result;
    
    // double an=1,s = an;
    // int n = 1;
    // while(fabs(an)>eps)
    // {((pow(-1, n) * pow(x, 2 * n)) / (2 * fac(n))); 
    //        an*=-x*x/(2.*n*(2*n-1));
    //        s+=an;
    //        n++;
    // }
    // return s;
}

int main(int argc, const char * argv[]) {
    float x;

    printf("Input x: ");
    scanf("%f", &x);

    float y = cosinus(x);
    printf("My cos: %.4f\tMath.h cos: %.4f\n", y, cos(x));
    return 0;
}
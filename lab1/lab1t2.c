#include <stdio.h>

float degree_of_number(int n, float x) {
    float num = x;
    for (int i = 1; i < n; i++) {
        x *= num;
    }
    return x;
}

int main() {
    int n;
    float x;
    printf("Input the number and degree:\n"); 
    scanf("%f", &x);
    scanf("%d", &n);
    if (n > 0 || n < 0) {
        float degree = degree_of_number(n, x);
        printf("Number %f to the degree of %d: %f\n", x, n, degree);
    } else if (n == 0) {
        printf("Number %f to the degree of %d: %d\n", x, n, 1);
    } else {
        printf("The number does not match the condition\n");
    }
    return 0;
}
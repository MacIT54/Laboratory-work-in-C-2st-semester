#include <stdio.h>

int gaus(int year) {
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = (19 * a + 15) % 30;
    int e = (2 * b + 4 * c + 6 * d + 6) % 7;
    int f = d + e;
    return f;
}

int main() {
    int easter, year;
    printf("Input the year: ");
    scanf("%d", &year);
    int f = gaus(year);
    if (f <= 26) {
        easter = 4 + f;
        printf("Easter date in %d: %d of April\n", year, easter);
    } else if (f > 26) {
        easter = f - 26;
        printf("Easter date in %d: %d of May\n", year, easter);
    }
    return 0;
}
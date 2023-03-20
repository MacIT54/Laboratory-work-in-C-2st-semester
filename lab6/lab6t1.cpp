#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void geom(float a, float b, float c, float *P, float *S) {
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        *P = a + b + c;
        float p = *P / 2;
        *S = sqrt(p * (p - a) * (p - b) * (p - c));
        // cout << "P = " << P << endl;
        // cout << "S = " << S << endl;
        cout << "Code: 1\n";

    } else {
        cout << "Input error, this triangle does not exist\n";
        cout << "Code: 0\n";
    }  
}

int main() {
    float a, b, c;
    float P, S;
    cout << "Input the sides of the triangle: \n";
    cin >> a >> b >> c;
    geom(a, b, c, &P, &S);
    cout << P;
    cout << S;
    return 0;
}
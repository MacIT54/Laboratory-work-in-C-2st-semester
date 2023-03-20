#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

float fac(float n) {
    if (n <= 1) {
        return 1;
    } 
    return n * fac(n - 1);
}

void probability(int n, int m, float &pd, float &pm) {
    float p = 0.45, q = 1 - p, Cnm;
    Cnm = fac(n) / (fac(m) * fac(n - m));
    pd = Cnm * pow(p, m) * pow(q, (n - m));
    pm = Cnm * pow(q, m) * pow(p, (n - m));
}

int main() {
    float pd, pm, n, m;
    cout << "Input number of kids and girls or boys: \n";
    cin >> n >> m;
    probability(n, m, pd, pm);
    cout << "Probability of girls: \n" << pd << "\n";
    cout << "Probability of boys: \n" << pm << "\n";
    //printf("%f ", pm);
    return 0;
}
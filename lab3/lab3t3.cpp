#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    int *a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n + 1; i++) a[i] = i;
    for (int p = 2; p < n + 1; p++)
        if (a[p] != 0) {
            cout << a[p] << endl;
            for (int j = p * p; j < n + 1; j += p) a[j] = 0;
        }
    free(a);
    return 0;
}
 

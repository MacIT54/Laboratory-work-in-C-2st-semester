#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void array_print(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%3d ", arr[i]);   
    printf("\n\n");
}

int main() {
    srand(time(0));
    int n, m, k;
    cout << "Input size of array: ";
    cin >> n;
    int *b = (int*)malloc(sizeof(int) * n);
    if (b == NULL) {
        return 0;
    }
    for (int i = 0; i < n; i++) 
        b[i] = -50 + rand() % 100;
    printf("%d\n", *(b+2));
    
    cout << "Array b:\n";
    array_print(b, n);
    for (int i = 0; i < n; i++) 
        if (b[i] >= 0) 
            m++; 
        k++; 
    int *c = (int*)malloc(sizeof(int) * m), *d = (int*)malloc(sizeof(int) * k), j = 0, j1 = 0;
    for (int i = 0; i < n; i++) 
        if (b[i] > 0) {
            c[j] = b[i];
            j++;
        }
    for (int i = 0; i < n; i++) 
        if (b[i] < 0) {
            d[j1] = b[i];
            j1++;
        }
    cout << "Array c:\n";
    array_print(c, j);
    cout << "Array d:\n";
    array_print(d, j1);
    free(b);
    free(c);
    free(d);
    return 0;
}
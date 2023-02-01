#include <iostream>

using namespace std;

int rek(int arr[], int k) {
    if (k < 10) {
        if (arr[k] < 0) {
            printf("%3d", arr[k]);
        } 
        rek(arr, k + 1);
        if (arr[k] > 0) {
            printf("%3d", arr[k]);
        }
    } else {
        return 0;
    }
    return 0;
}

int main() {
    int arr[10] = {-12, -10, 35, 1, -6, 50, 6, -33, 54, 3}, k = 0;
    rek(arr, k);
    cout << "\n";
    return 0;
}
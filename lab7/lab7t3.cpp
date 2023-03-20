#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

void Sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
            }
        }
    }
}

void PrintMas(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d", arr[i]);   
    }
    printf("\n\n");
}

void Select(int *arr, int ans[], int n, int &C, int key, int &h) {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        C++;
        if (arr[i] == key) {
            ans[h++] = i;
        }
    }
    if (h != 0) { 
        for (int i = 0; i < h; i++) {
            cout << "Key " << key << " in cell " << ans[i] << endl;
        }
    } else {
        cout << "\nKey " << key << " not found\n";
    }
}

void Bin(int* arr, int count, int key, int &C) {
int l = 0, r = count - 1, m = 0;
    bool flag = 0;
    while (l <= r) {
        m = round((l + r) / 2);
        C++;
        if (arr[m] == key) {
            flag = 1;
            break;
        }
        C++;
        if (arr[m] < key) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    //cout << C << "\n";
    if (flag) {
        cout << "Index of the element: " << key << " in array is: " << m << endl;
    } else {
        cout << "Key not found\n";
    }
}

int main() {
    int C = 0, ans[100], ans1[100], n = 100, n1 = 1000, key, h = 0, h1 = 0, m;
    cout << "Input key: ";
    cin >> key;
    int *arr = (int*)malloc(sizeof(int) * n), *arr1 = (int*)malloc(sizeof(int) * n);
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50;
    }
    for (int i = 0; i < n1; i++) {
        arr1[i] = rand() % 50;
    }
    Sort(arr, n);
    Sort(arr1, n1);
    PrintMas(arr, n);
    PrintMas(arr1, n1);
    cout << "<Searching through elements>\n\n";
    cout << "Search in an array with a size of 100: ";
    Select(arr, ans, n, C, key, h);
    cout << "Comparisons: " << C << "\n" << endl;
    C = 0;
    cout << "Search in an array with a size of 1000: ";
    Select(arr1, ans1, n1, C, key, h1);
    cout << "Comparisons: " << C << "\n" << endl;
    C = 0;
    cout << "\n<Searching for elements by binary search>\n\n";
    cout << "Search in an array with a size of 100: ";
    Bin(arr, n, key, C);
    cout << "\nComparisons: " << C << "\n" << endl;
    C = 0;
    cout << "Search in an array with a size of 1000: ";
    Bin(arr1, n1, key, C);
    cout << "\nComparisons: " << C << "\n" << endl;
    return 0;
}


#include <iostream>
#include <cstdlib>

using namespace std;

void array_print(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%3d ", arr[i]);   
    printf("\n");
}

void mass(int *mass, int n) {
    int j = 0, j1 = 0;
    int min1, min2;
    min1 = min2 = 100000;
    for (int i = 0; i < n; i++) {
        if (mass[i] < min1) 
            min1 = mass[i];
    }
    for (int i = 0; i < n; i++) {
        if (mass[i] < min2 && mass[i] != min1) 
            min2 = mass[i]; 
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (mass[i] == min1) {
            j = i + 1;
        } else if (mass[i] == min2) {
            j1 = i + 1;
        }
    }
    if (j < j1 && j + 1 != j1 && j - 1 != j1) {
        do {
        mass[j++] = 0;
    } while (mass[j] != min2);
    } else if (j > j1 && j + 1 != j1 && j - 1 != j1) {
        do {
        mass[j1++] = 0;
    } while (mass[j1] != min1);
    }
}

int main() {
    srand(time(0));
    int n = 30;
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50;
    }
    array_print(arr, n);
    mass(arr, n);
    array_print(arr, n);
    return 0;
}
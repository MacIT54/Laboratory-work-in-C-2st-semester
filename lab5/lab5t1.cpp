#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void array_print(int **array, int n, int m) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
} 

void mini_array_print(int *array, int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%2d ", array[i]);
    }
    printf("\n");
}

void array_free(int **A, size_t N) {
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}

int main() {
    srand(time(0));
    int n, k, mk, km, max = -100, m, p = 0;
    cout << "input m: ";
    cin >> m;
    int *A = (int*)malloc(m * sizeof(int));
    int **B = (int **)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        B[i] = (int *)malloc(k * sizeof(int));
    } 
    for (int i = 0; i < m; i++) {
        A[i] = rand() % 50;
    }
    cout << "Input k, ATTENTION, k less than m: ";
    cin >> k;
    cout << "Array A: ";
    mini_array_print(A, m);
    n = m / k;
    if (m % k) n++;  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {            
            if (p < m) {
                B[i][j] = A[p++];
            }
        }
    } 
    cout << "\nArray B:\n";
    array_print(B, n, k);
    free(A);
    array_free(B, n);
    return 0;
}
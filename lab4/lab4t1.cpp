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

int main() {
    srand(time(0));
    int n = 5, m;
    cout << "input m: ";
    cin >> m;
    int **B = (int **)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        B[i] = (int *)malloc(m * sizeof(int));
    }
    int **C = (int **)malloc((n) * sizeof(int*));
        for (int i = 0; i < n; ++i) C[i] = (int *)malloc((m) * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            B[i][j] = -10 + rand() % 100;
    printf("Matrix B(n, m):\n");
    array_print(B, n, m);
    int max = -100, mi, mj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (B[i][j] > max) {
                max = B[i][j];
            }
            if (B[i][j] == max) {
                mi = i;
                mj = j;
            }
        }
    }
    printf("\nMaximum element in the array B: %d\n\n", max);
    for (int i = mi; i < n - 1; i++) 
        for (int j = 0; j < m; j++) 
            B[i][j] = B[i + 1][j];
    for (int i = 0; i < n; i++) 
        for (int j = mj; j < m - 1; j++) 
            B[i][j] = B[i][j + 1]; 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = B[i][j];
    printf("Matrix C(n - 1, m - 1):\n");
    array_print(C, n - 1, m - 1);
    free(B);
    free(C);
    return 0;
}
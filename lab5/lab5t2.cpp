#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void array_free(int **A, int N) {
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}

int main() {
    int n = 9, s = 1, k = 1;
    int **arr = (int **)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(((i + 1) * sizeof(int)) - 1);
    } 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            arr[i][0] = i + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < i + 1; j++) {
            arr[i][j] = s * k;
            k++;
        }
        k = 2;
        s++;
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    array_free(arr, n);
    return 0;
}
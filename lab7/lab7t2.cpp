#include <iostream>
#include <cstdlib>

using namespace std;

void SumStr(int **arr1, int *Smas1, int *dop, int total, int n1) {
    for (int i = 0; i < n1; i++) {
        total = 0;
        for (int j = 0; j < Smas1[i]; j++) {
            total += arr1[i][j];
        }
        dop[i] = total;
    }
}

int main() {
    srand(time(0));
    int n = 10, sum = 0, total = 0, n1 = n + 1;
    int *Smas = (int*)malloc(n * sizeof(int));
    int *Smas1 = (int*)malloc(n1 * sizeof(int));
    for (int i = 0; i < n; i++) {
        Smas[i] = 2 + rand() % (10 - 2);
    }
    for (int i = 0; i < n; i++) {
        Smas1[i] = Smas[i] + 1;     
    }
    int *dop = (int*)malloc(sizeof(int) * n);
    int **arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(((Smas[i]) * sizeof(int)) - 1);
    }
    int **arr1 = (int**)malloc(n1 * sizeof(int*));
    for (int i = 0; i < n1; i++) {
        arr1[i] = (int*)malloc(((Smas1[i]) * sizeof(int)) - 1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < Smas[i]; j++) {
            arr[i][j] = rand() % 30;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < Smas[i]; j++) {
            arr1[i][j] = arr[i][j];
        }
    }
    SumStr(arr1, Smas1, dop, total, n1);
    for (int i = 0; i < n; i++) {
        arr1[i][0] = dop[i];
    }
    printf("\n");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < Smas[i]; j++) {
            printf("%3d ", arr1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
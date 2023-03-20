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

void array_free(int **A, size_t N) {
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}

void mini_array_print(int *array, int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%3d ", array[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int n, m, sum = 0, sum_str = 0, sum_stol = 0, total, total1;
    cout << "input n and m: ";
    cin >> n;
    cin >> m;
    int n1 = n + 1, m1 = m + 1;
    int **A = (int **)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = (int *)malloc(m * sizeof(int));
    }
    int **D = (int **)malloc(n1 * sizeof(int*));
    for (int i = 0; i < n1; i++) {
        D[i] = (int *)malloc(m1 * sizeof(int));
    }
    int *dop1 = (int*)malloc(sizeof(int) * n1);
    int *dop2 = (int*)malloc(sizeof(int) * m1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = -10 + rand() % 100;
        }
    }
    printf("Matrix A(n, m):\n");
    array_print(A, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += A[i][j];
        }
    }
    printf("%d\n", sum);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            D[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            if ((i == n) && (j == m)) {
                D[i][j] = sum;
            }
        }
    }    
    for (int i = 0; i < n1; i++) {
        total = 0;
        for (int j = 0; j < m1; j++) {
            total += D[i][j];
        }
        //cout << "Sum of rows:" << i + 1 << "is:" << total << "\n" << endl;
        dop1[i] = total;
    }
    for (int j = 0; j < m1; j++) {
        total1 = 0;
        for (int i = 0; i < n1; i++) {
            total1 += D[i][j];
        }
        //cout << "Sum of cols:" << j + 1 << "is:" << total1 << endl;
        dop2[j] = total1;
    }
    for (int i = 0; i < n1; i++) {
        D[i][m] = dop1[i];
    }
    for (int i = 0; i < m1; i++) {
        D[n][i] = dop2[i];
    }
    mini_array_print(dop1, n1);
    mini_array_print(dop2, m1);
    printf("Matrix D(n + 1, m + 1):\n");
    array_print(D, n1, m1);
    array_free(A, n);
    array_free(D, n1);
    free(dop1);
    free(dop2);
    return 0;
}
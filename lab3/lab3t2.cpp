#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void array_print(float *arr, int n) {
    for (int i = 0; i < n; i++) printf("%3f ", arr[i]);   
    printf("\n");
}

int main() {
    srand(time(0));
    float *a, *p;
    float **a_sort;
    int n, N, j, i, k = 1;
    cout << "Input size of array: ";
    cin >> N;
    a = new float [N];
    a_sort = new float* [N];
    for (i = 0; i < N; i++) {
        a[i] = (float) (rand() % 10001 / 100); 
        a_sort[i] = a + i;
    }
    cout << "Array a:\n";
    array_print(a, N);
    cout << "\nArray of pointers:\n";
    for (i = 0; i < N; i++) {
        printf("%p ", a_sort[i]);
    }
    cout << "\n";
    for (n = 1; k; n++) {
        k = 0;
        for (j = 0; j < N - n; j++) {
            if (*a_sort[j] > *a_sort[j + 1]) {
                k = 1;
                p = a_sort[j];
                a_sort[j] = a_sort[j + 1];
                a_sort[j + 1] = p;               
            }
        }
    }
    cout << "\nArray 'a' with sorting:\n";
    for (i = 0; i < N; i++) {
        printf("%10d ", a_sort[i]);
    }
    cout << "\n\n";
    for (i = 0; i < N; i++) {
        printf("%10f ", *a_sort[i]);  
    }
    cout << "\n\n";
    free(a);
    free(a_sort);
    return 0;
}
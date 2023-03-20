#include "func.h"
#include <iostream>
#include <ctime>

using namespace std;

void print_arr_d(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);   
    }
    printf("\n\n");
}

void print_arr_f(float *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);   
    }
    printf("\n\n");
}

void bubble_sort_d(int *arr, int n) {
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

void shaker_sort_d(int* arr, int n) {
    int l = 0; int r = n - 1; int k = n;
    do {
        for (int j = r; j > l; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                k = j;
            }
        }
        l = k;
        for (int j = l; j < r; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                k = j;
            }
        }
        r = k;
    } while (l < r);
}

void bubble_sort_f(float *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                float b = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
            }
        }
    }
}

void shaker_sort_f(float* arr, int n) {
    int l = 0; int r = n - 1; int k = n;
    do {
        for (int j = r; j > l; j--) {
            if (arr[j] < arr[j - 1]) {
                float temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                k = j;
            }
        }
        l = k;
        for (int j = l; j < r; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                k = j;
            }
        }
        r = k;
    } while (l < r);
}

double timer_d(char* type_sort, int* arr, int n) {
    if (strcmp(type_sort, "Bubble") == 0) {
        clock_t start = clock();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int b = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = b;
                }
            }    
        }
        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        return seconds;
    } else if (strcmp(type_sort, "Shaker") == 0) {
        clock_t start = clock();
        int l = 0; int r = n - 1; int k = n;
        do {
            for (int j = r; j > l; j--) {
                if (arr[j] < arr[j - 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                    k = j;
                }
            }
            l = k;
            for (int j = l; j < r; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    k = j;
                }
            }
            r = k;
        } while (l < r);
        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        return seconds;
    }
}

double timer_f(char* type_sort, float* arr, int n) {
    if (strcmp(type_sort, "Bubble") == 0) {
        clock_t start = clock();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    float b = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = b;
                }
            }    
        }
        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        return seconds;
    } else if (strcmp(type_sort, "Shaker") == 0) {
        clock_t start = clock();
        int l = 0; int r = n - 1; int k = n;
        do {
            for (int j = r; j > l; j--) {
                if (arr[j] < arr[j - 1]) {
                    float temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                    k = j;
                }
            }
            l = k;
            for (int j = l; j < r; j++) {
                if (arr[j] > arr[j + 1]) {
                    float temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    k = j;
                }
            }
            r = k;
        } while (l < r);
        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        return seconds;
    }
}
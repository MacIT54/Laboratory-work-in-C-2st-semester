#include "func.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    cout << "\n*** Welcome to the program that sorts the array and shows the sorting time ***\n";
    cout << "\n*** Please input the size of the array and the data type of the array elements ***\n";
    cout << "\n*** If integer then input 'i', if float then input 'f' ***\n";
    int n;
    double time;
    char type_data[5];
    cin >> n;
    cin >> type_data;
    if (strcmp(type_data, "i") == 0) {
        int *arr_d = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr_d[i] = rand() % 100;         
        }
        cout << "\n*** Now select the sort type ***\n";
        cout << "\n*** Bubble or Shaker ***\n";
        char type_sort[20];
        cin >> type_sort;
        if (strcmp(type_sort, "Bubble") == 0) {
            time = timer_d("Bubble", arr_d, n);
            cout << "\n*** Bubble sorting execution time: " << time << " ***\n";
        } else if (strcmp(type_sort, "Shaker") == 0) {
            time = timer_d("Shaker", arr_d, n);
            cout << "\n*** Shaker sorting execution time: " << time << " ***\n";
        }
        // cout << "\nArray before sorting:\n";
        // print_arr_d(arr_d, n);
        // cout << "\nArray after sorting:\n";
        // bubble_sort_d(arr_d, n);
        // print_arr_d(arr_d, n);
        delete[] arr_d;
        exit(0);
    } else if (strcmp(type_data, "f") == 0) {
        float *arr_f = (float*)malloc(n * sizeof(float));
        for (int i = 0; i < n; i++) {
            arr_f[i] = rand() % 100;       
        }
        cout << "\n*** Now select the sort type ***\n";
        cout << "\n*** Bubble or Shaker ***\n";
        char type_sort[20];
        cin >> type_sort;
        if (strcmp(type_sort, "Bubble") == 0) {
            time = timer_f("Bubble", arr_f, n);
            cout << "\n*** Bubble sorting execution time: " << time << " ***\n";
        } else if (strcmp(type_sort, "Shaker") == 0) {
            time = timer_f("Shaker", arr_f, n);
            cout << "\n*** Shaker sorting execution time: " << time << " ***\n";
        }
        // cout << "\nArray before sorting:\n";
        // print_arr_f(arr_f, n);
        // cout << "\nArray after sorting:\n";
        // bubble_sort_f(arr_f, n);
        delete[] arr_f;
        exit(0);
    } else {
        cout << "\nYour input is not defined\n";
        exit(0);
    }
    // float *arr_f = (float*)malloc(n * sizeof(float));
    // for (int i = 0; i < n; i++) {
    //     arr_d[i] = rand() % 100;
    //     arr_f[i] = rand() % 100;
    // }
    // print_arr_d(arr_d, n);
    // print_arr_f(arr_f, n);
    // bubble_sort_d(arr_d, n);
    // bubble_sort_f(arr_f, n);
    // print_arr_d(arr_d, n);
    // print_arr_f(arr_f, n);
    return 0;
}
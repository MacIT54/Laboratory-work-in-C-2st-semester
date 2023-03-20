#include <iostream>

using namespace std;

struct Students {
    int NumSchool;
    int Graduates;
    int Applicants;
};

void IndexSort(int *arr, int n, int *B);

int main() {
    const int n = 3;
    int *index = new int[n];
    int *arr1 = (int*)malloc(n * sizeof(int));
    Students arr[n] = {80, 70, 60, 60, 123, 110, 110, 89, 70};
    for (int i = 0; i < n; i++) {
        if (arr[i].Applicants > arr[i].Graduates) {
            cout << "\nError in number of applicants!\n";
            exit(0);
        } else {
            cout << "\nSchool:\t" << arr[i].NumSchool << "\t Number of graduates:\t" << 
            arr[i].Graduates << "\t Number of applicants:\t" << arr[i].Applicants;
        }
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        arr1[i] = (((float)arr[i].Applicants / (float)arr[i].Graduates) * 100);
    }
    cout << "\n";
    IndexSort(arr1, n, index);
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << "\nSchool:\t" << arr[index[i]].NumSchool << "\t Number of graduates:\t" << 
        arr[index[i]].Graduates <<  "\t Number of applicants:\t" << arr[index[i]].Applicants << 
        "\t Percent of applicants:\t" << arr1[index[i]]; 
    }
    cout << "\n";
    return 0;
}

void IndexSort(int *arr, int n, int *index) {
    int i, j, t = 0;
    for (i = 0; i < n; i++) {
        index[i] = i;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; ++j) {
            if (arr[index[i]] < arr[index[j]]) {
                t = index[i];
                index[i] = index[j];
                index[j] = t;
            }
        }
    }
}

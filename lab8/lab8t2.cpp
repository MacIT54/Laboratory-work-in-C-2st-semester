#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <string>

using namespace std;

struct room {
    int number;
    int area;
    char faculty[50];
    int countRes;
};

int main() {
    const int n = 5;
    int k = 0, k1 = 0, k2 = 0, sumStud = 0, area1 = 0, area2 = 0, area3 = 0, sumArea1 = 0, sumCount1 = 0,
    sumArea2 = 0, sumCount2 = 0, sumArea3 = 0, sumCount3 = 0;
    room arr[n] = {101, 15, "IVT", 3, 102, 14, "IVT", 3, 103, 16, "IS", 2, 104, 16, "IS", 3 , 105, 16, "MRM", 2};
    char arrf[n];
    for (int i = 0; i < n; i++) {
        cout << "\nNumber of room:\t" << arr[i].number << "\t Area of room:\t" << 
        arr[i].area << "\t Name of the faclulty:\t" << arr[i].faculty << 
        "\t Number of residents:\t" << arr[i].countRes;
    }
    cout << "\n";
    // cout << "\nNames of the different faculties: ";
    for (int i = 0, j = i + 1; i < n; i++) {
        if (strcmp(arr[i].faculty, arr[i + 1].faculty) != 0) {
            k += 1;
            strcpy(arrf, arr[i].faculty);
            // cout << arrf << "\n";
            // cout << k << "\n";
        } 
    }
    for (int i = 0; i < n; i++) {
        if (arr[i].number != arr[i + 1].number) {
            k1 += 1;
        }
    }
    for (int i = 0; i < n; i++) {
        sumStud += arr[i].countRes;
    }
    for (int i = 0; i < n; i++) {
        if (strncmp(arr[i].faculty, "IVT", 3) == 0) {
            sumArea1 += arr[i].area;
            sumCount1 += arr[i].countRes;
            area1 =  sumArea1 / sumCount1;
        } else if (strncmp(arr[i].faculty, "IS", 2) == 0) {
            sumArea2 += arr[i].area;
            sumCount2 += arr[i].countRes;
            area2 =  sumArea2 / sumCount2;
        } else if (strncmp(arr[i].faculty, "MRM", 3) == 0) {
            sumArea3 += arr[i].area;
            sumCount3 += arr[i].countRes;
            area3 =  sumArea3 / sumCount3;
        }
    }
    cout << "\nNumber of rooms: " << k1;
    cout << "\nNumber of students: " << sumStud;
    cout << "\nAverage area IVT: " << area1 << "\nAverage area IS: " << area2 << "\nAverage area MRM: " << area3;
    cout << "\n";
    return 0;
}
#include <iostream>

using namespace std;

int rek(int number) {
    if (number > 1) {
        rek(number / 2);
    }
    cout << number % 2;
    return number;
}

int main() {
    printf("Input the decimal number to be converted to binary: ");
    int number;
    cin >> number;
    printf("Result: ");
    rek(number);
    cout << "\n";
    return 0;
}
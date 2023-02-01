#include <iostream>
#include <cstdio>

using namespace std;

int rek(int number) {
    if (number != 0) {
        rek(number + 1);
    } else {
        return 0;
    }  
    return 0; 
}

int main() {
    int number;
    cout << "Input numbers: ";
    cin >> number;
    int result = rek(number);
    printf("Result: ");
    cout << result;
    cout << "\n";
    return 0;
}

// int rek(int number) {
//     if (number == 0) {
//         return 0;
//     } else {
//         if (number > 0) {
//             if (number % 2 == 0) {
//                 return rek(number) + 1;
//                 std::cout << number <<std::endl;
//             }
//         }
//     }
// }
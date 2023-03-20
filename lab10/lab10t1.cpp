#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cctype>
#include <vector>
#include <list>

using namespace std;

int main() {
    FILE *file1;
    FILE *file2 = fopen("output.txt", "w");
    if ((file1 = fopen ("input.txt", "r")) == NULL) {
        cout << "File not found\n";
    }
    int n = 0;
    char strings[9][20], str[20];
    while (feof(file1) == 0) {
        fscanf(file1, "%s", str);
        for (int i = 0; i < 20; i++)
            if (str[i] == '.' || str[i] == ',') {
                str[i] = '\0'; 
            }
        // for (int i = 0; i < 20; i++) {
        //     if (str[i] == '\0') {
        //         str[i] = ' ';
        //     }
        // }
        cout << str;
        strcpy(strings[n++], str);
        // for (int i = 0; i < 20; i++)
        //     for (int j = 0; j <= strlen(strings[i]); j++)
        //         if (strings[j] == strlen(strings[i])) {
        //             strings[i + 1] = ' '; 
        //         }
    }
    fclose(file1);
    // for (int i = 0; i < n; i++)
    //     printf("%s\n", strings[i]);
    cout << "\n";
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                strcpy(str, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], str);
            }
    for (int i = 0; i < n; i++) {
        if (file2) {
            char *str2 = strings[i]; 
            fputs(str2, file2); 
        }
        printf("%s\n", strings[i]);
    }
    fclose(file2);
    return 0;
}
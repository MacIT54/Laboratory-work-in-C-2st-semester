#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

struct pass {
    char fname[30];
    char name[30];
    char fathname[30];
    char numberLugg[10];
    char totalWeight[10];
} st;

#define N 3

void add_new_f(char *name);

void print_f(char *name);

void add_in_end(char *name);

void find_and_del(char *name);

void change_weight(char *name);

int main() {
    int key, a = 0;
    do {
        puts("  1 - Add new file");
        puts("  2 - Show the file");
        puts("  3 - Add in file");
        puts("  4 - Find and delete an entry of passengers whose total weight is less than 10 kg");
        puts("  5 - Change the weight of things");
        puts("  0 - Exit");
        cin >> key;
        switch (key) {
        case 0:
            puts("Shutting down");
            break;
        case 1:
            add_new_f("f1.dat");
            break;
        case 2:
            print_f("f1.dat");
            break;
        case 3:
            add_in_end("f1.dat");
            break;
        case 4:
            find_and_del("f1.dat");
            break;
        case 5:
            change_weight("f1.dat");
            break;
        default:
            puts("Your input is not defined");
        }
    } while (key != 0);
    return 0;
}

void add_new_f(char *name) {
    FILE *f1;
    pass arr[N] = {{"Madison", "James", "Birks", "2", "20"}, {"Washington", "George", "Ogastins", "3", "47"}, 
    {"Jefferson", "Thomas", "Peters", "1", "8"}};
    cout << "\nInput data\n";
    f1 = fopen(name, "wb"); 
    fwrite(arr, sizeof(pass), N, f1);
    fclose(f1);
}

void print_f(char *name) {
    FILE *f1;
    f1 = fopen(name, "rb+");
    cout << "\n";
    while (fread(&st, sizeof(pass), 1, f1)) {
        if (st.fname[0] != 0) {
            cout << st.fname << " " << st.name << " " << st.fathname << " " << st.numberLugg << " " << st.totalWeight << endl;
        }
    } 
    cout << "\n";
    fclose(f1);
}

void add_in_end(char *name) {
    FILE *f1;
    f1 = fopen(name, "ab"); 
    puts("First name: "); scanf("%s", &st.fname);
    puts("Name: "); scanf("%s", &st.name);
    puts("Father name: "); scanf("%s", &st.fathname);
    puts("Number of lugged: "); scanf("%s", &st.numberLugg);
    puts("Total weight: "); scanf("%s", &st.totalWeight);
    fwrite(&st, sizeof(st), 1, f1); 
    fclose(f1);
}

void find_and_del(char *name) {
    FILE *f1;
    f1 = fopen(name, "rb+");
    while (fread(&st, sizeof(pass), 1, f1)) {
        if (atoi(st.totalWeight) < 10) {
            fseek(f1, -sizeof(pass), 1);
            st.fname[0] = 0;
            fwrite(&st, sizeof(pass), 1, f1);
            fflush(f1);
            puts("Write has been deleted");
        } 
    }
    fclose(f1);
}

void change_weight(char *name) {
    char fn[20], wg[5];
    FILE *f1;
    f1 = fopen(name, "rb+");
    puts("Input fname");
    cin >> fn;
    puts("Input new weight: ");
    cin >> wg;
    while (fread(&st, sizeof(pass), 1, f1)) {
        if (strcmp(st.fname, fn) == 0) {
            fseek(f1, -sizeof(pass), 1);
            strcpy(st.totalWeight, wg);
            fwrite(&st, sizeof(pass), 1, f1);
            fflush(f1);
        } 
    }
    fclose(f1);
}
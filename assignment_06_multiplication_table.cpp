#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_MULTIPLIER = 12;


void printSingleTable(int num);
void printTablesUpTo(int n);


int main() {
    // ---- Part A: Single table ----
    int number;
    cout << "Enter a number: ";
    cin >> number;

    printSingleTable(number);

    
    int n;
    cout << "\nEnter N (to print tables 1 through N): ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    printTablesUpTo(n);

    return 0;
}


void printSingleTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= MAX_MULTIPLIER; i++) {
        cout << num << "  x  " << setw(2) << left << i
             << " = " << setw(4) << left << (num * i) << endl;
    }
}


void printTablesUpTo(int n) {
    for (int num = 1; num <= n; num++) {
        printSingleTable(num);
        if (num < n) {
            cout << "---------------------------" << endl;
        }
    }
}

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
bool divide(double a, double b, double& result);
bool computeModulus(double a, double b, double& result);
double exponentiate(double base, double exponent);
bool getTwoNumbers(double& a, double& b);


int main() {
    int choice;

    cout << fixed << setprecision(2);

    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 7." << endl;
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
            continue;
        }

        double a, b;
        if (!getTwoNumbers(a, b)) {
            cout << "Invalid number entered." << endl;
            continue;
        }

        double result;
        switch (choice) {
            case 1:
                result = add(a, b);
                cout << "Result: " << a << " + " << b << " = " << result << endl;
                break;
            case 2:
                result = subtract(a, b);
                cout << "Result: " << a << " - " << b << " = " << result << endl;
                break;
            case 3:
                result = multiply(a, b);
                cout << "Result: " << a << " * " << b << " = " << result << endl;
                break;
            case 4:
                if (divide(a, b, result)) {
                    cout << "Result: " << a << " / " << b << " = " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                break;
            case 5:
                if (computeModulus(a, b, result)) {
                    cout << "Result: " << a << " % " << b << " = " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                break;
            case 6:
                result = exponentiate(a, b);
                cout << "Result: " << a << " ^ " << b << " = " << result << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}


void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

bool getTwoNumbers(double& a, double& b) {
    cout << "Enter first number : ";
    cin >> a;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }

    cout << "Enter second number: ";
    cin >> b;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }

    return true;
}


double add(double a, double b) {
    return a + b;
}



double subtract(double a, double b) {
    return a - 
double multiply(double a, double b) {
    return a * b;
}
bool divide(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }
    result = a / b;
    return true;
}


bool computeModulus(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }
    result = fmod(a, b);
    return true;
}


double exponentiate(double base, double exponent) {
    return pow(base, exponent);
}

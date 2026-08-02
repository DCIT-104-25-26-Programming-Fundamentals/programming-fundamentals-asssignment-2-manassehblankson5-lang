
// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================

#include <iostream>
using namespace std;

// Function prototypes
double calculateSum(const double arr[], int size);
double calculateAverage(double sum, int size);
double findMaximum(const double arr[], int size);
double findMinimum(const double arr[], int size);

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    // Requirement: N must be a positive integer
    if (n <= 0) {
        cout << "Error: Number of elements must be greater than zero." << endl;
        return 1;
    }

    // Allocate array dynamically to fit user size N
    double* numbers = new double[n];

    // Read elements from user
    for (int i = 0; i < n; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Perform statistical calculations using functions
    double sum = calculateSum(numbers, n);
    double avg = calculateAverage(sum, n);
    double maxVal = findMaximum(numbers, n);
    double minVal = findMinimum(numbers, n);

    // Display results
    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << avg << endl;
    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;

    // Free dynamically allocated memory
    delete[] numbers;

    return 0;
}

// Function to compute the sum of array elements
double calculateSum(const double arr[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        total += arr[i];
    }
    return total;
}

// Function to compute the average from the total sum
double calculateAverage(double sum, int size) {
    return sum / size;
}

// Function to find the maximum element manually
double findMaximum(const double arr[], int size) {
    double maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to find the minimum element manually
double findMinimum(const double arr[], int size) {
    double minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

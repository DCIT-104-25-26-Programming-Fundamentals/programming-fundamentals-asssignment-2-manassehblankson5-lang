#include <iostream>
using namespace std;


int computeSum(int arr[], int n);
double computeAverage(int arr[], int n);
int computeMax(int arr[], int n);
int computeMin(int arr[], int n);


int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

  
    if (n <= 0) {
        cout << "Error: The number of values must be a positive integer." << endl;
        return 1;
    }

 
    int* numbers = new int[n];

  
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

  
    int sum = computeSum(numbers, n);
    double average = computeAverage(numbers, n);
    int maximum = computeMax(numbers, n);
    int minimum = computeMin(numbers, n);

   
    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;
 
    
   delete[] numbers;

    return 0;
}


int computeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}


double computeAverage(int arr[], int n) {
    int sum = computeSum(arr, n);
    return static_cast<double>(sum) / n;
}



int computeMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


int computeMin(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

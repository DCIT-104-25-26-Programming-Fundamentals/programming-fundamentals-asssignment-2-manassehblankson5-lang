// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
//
// =============================================================================
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------
bool getDimension(const string& prompt, int& value);
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& label);
void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int rowsA, int colsA, int colsB,
                       int result[MAX_SIZE][MAX_SIZE]);

void runTranspose();
void runAddition();
void runMultiplication();

// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------
int main() {
    int choice;

    do {
        cout << "\n===== Matrix Operations Menu =====" << endl;
        cout << "1. Transpose a Matrix" << endl;
        cout << "2. Add Two Matrices" << endl;
        cout << "3. Multiply Two Matrices" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                runTranspose();
                break;
            case 2:
                runAddition();
                break;
            case 3:
                runMultiplication();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

// -----------------------------------------------------------------------------
// getDimension
// Prompts for a matrix dimension and validates it is between 1 and MAX_SIZE.
// Returns true if valid, false otherwise (after printing an error message).
// -----------------------------------------------------------------------------
bool getDimension(const string& prompt, int& value) {
    cout << prompt;
    cin >> value;

    if (value <= 0 || value > MAX_SIZE) {
        cout << "Error: Dimension must be between 1 and " << MAX_SIZE << "." << endl;
        return false;
    }
    return true;
}

// -----------------------------------------------------------------------------
// readMatrix
// Reads rows*cols elements from the user, one at a time, into mat.
// -----------------------------------------------------------------------------
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// printMatrix
// Displays a matrix in a neat, aligned grid using setw().
// -----------------------------------------------------------------------------
void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& label) {
    cout << "\n" << label << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// transposeMatrix
// Computes the transpose of an rows x cols matrix (result is cols x rows).
// -----------------------------------------------------------------------------
void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// addMatrices
// Computes the element-wise sum of two rows x cols matrices.
// -----------------------------------------------------------------------------
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// multiplyMatrices
// Computes the product of an (rowsA x colsA) matrix and a (colsA x colsB)
// matrix, producing a (rowsA x colsB) result.
// -----------------------------------------------------------------------------
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int rowsA, int colsA, int colsB,
                       int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

// -----------------------------------------------------------------------------
// runTranspose
// Handles Part A: read a matrix, transpose it, and display both.
// -----------------------------------------------------------------------------
void runTranspose() {
    int rows, cols;
    if (!getDimension("Enter number of rows: ", rows)) return;
    if (!getDimension("Enter number of columns: ", cols)) return;

    int mat[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    readMatrix(mat, rows, cols);
    transposeMatrix(mat, rows, cols, result);

    printMatrix(mat, rows, cols, "Original Matrix");
    printMatrix(result, cols, rows, "Transposed Matrix");
}

// -----------------------------------------------------------------------------
// runAddition
// Handles Part B: read two same-sized matrices, add them, and display all three.
// -----------------------------------------------------------------------------
void runAddition() {
    int rows, cols;
    if (!getDimension("Enter number of rows: ", rows)) return;
    if (!getDimension("Enter number of columns: ", cols)) return;

    int a[MAX_SIZE][MAX_SIZE];
    int b[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    cout << "\n-- Enter Matrix A --" << endl;
    readMatrix(a, rows, cols);

    cout << "\n-- Enter Matrix B --" << endl;
    readMatrix(b, rows, cols);

    addMatrices(a, b, rows, cols, result);

    printMatrix(a, rows, cols, "Matrix A");
    printMatrix(b, rows, cols, "Matrix B");
    printMatrix(result, rows, cols, "Sum (A + B)");
}

// -----------------------------------------------------------------------------
// runMultiplication
// Handles Part C: read matrix A (M x N) and matrix B (N x P), multiply, display.
// -----------------------------------------------------------------------------
void runMultiplication() {
    int rowsA, colsA, rowsB, colsB;

    if (!getDimension("Enter number of rows for Matrix A: ", rowsA)) return;
    if (!getDimension("Enter number of columns for Matrix A: ", colsA)) return;
    if (!getDimension("Enter number of rows for Matrix B: ", rowsB)) return;
    if (!getDimension("Enter number of columns for Matrix B: ", colsB)) return;

    if (colsA != rowsB) {
        cout << "Error: Number of columns in A must equal number of rows in B."
             << endl;
        return;
    }

    int a[MAX_SIZE][MAX_SIZE];
    int b[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    cout << "\n-- Enter Matrix A --" << endl;
    readMatrix(a, rowsA, colsA);

    cout << "\n-- Enter Matrix B --" << endl;
    readMatrix(b, rowsB, colsB);

    multiplyMatrices(a, b, rowsA, colsA, colsB, result);

    printMatrix(a, rowsA, colsA, "Matrix A");
    printMatrix(b, rowsB, colsB, "Matrix B");
    printMatrix(result, rowsA, colsB, "Product (A x B)");
}

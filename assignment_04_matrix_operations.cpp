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
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
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
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols) {
    int transpose[10][10];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transposed Matrix:" << endl;
    displayMatrix(transpose, cols, rows);
}

void addMatrices(int first[10][10], int second[10][10], int rows, int cols) {
    int result[10][10];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }

    cout << "Result of Addition:" << endl;
    displayMatrix(result, rows, cols);
}

void multiplyMatrices(int first[10][10], int second[10][10], int rowsA, int colsA, int rowsB, int colsB) {
    int result[10][10] = {0};

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    cout << "Result of Multiplication:" << endl;
    displayMatrix(result, rowsA, colsB);
}

int main() {
    int choice;

    cout << "Matrix Operations" << endl;
    cout << "1. Transpose a matrix" << endl;
    cout << "2. Add two matrices" << endl;
    cout << "3. Multiply two matrices" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        int matrix[10][10];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "Enter matrix elements:" << endl;
        readMatrix(matrix, rows, cols);
        cout << "Original Matrix:" << endl;
        displayMatrix(matrix, rows, cols);
        transposeMatrix(matrix, rows, cols);
    } else if (choice == 2) {
        int rows, cols;
        int first[10][10], second[10][10];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "Enter first matrix elements:" << endl;
        readMatrix(first, rows, cols);
        cout << "Enter second matrix elements:" << endl;
        readMatrix(second, rows, cols);
        addMatrices(first, second, rows, cols);
    } else if (choice == 3) {
        int rowsA, colsA, rowsB, colsB;
        int first[10][10], second[10][10];

        cout << "Enter rows for matrix A: ";
        cin >> rowsA;
        cout << "Enter columns for matrix A: ";
        cin >> colsA;
        cout << "Enter rows for matrix B: ";
        cin >> rowsB;
        cout << "Enter columns for matrix B: ";
        cin >> colsB;

        if (colsA != rowsB) {
            cout << "Error: Number of columns in A must equal number of rows in B." << endl;
            return 0;
        }

        cout << "Enter matrix A elements:" << endl;
        readMatrix(first, rowsA, colsA);
        cout << "Enter matrix B elements:" << endl;
        readMatrix(second, rowsB, colsB);
        multiplyMatrices(first, second, rowsA, colsA, rowsB, colsB);
    } else if (choice == 4) {
        cout << "Goodbye!" << endl;
    } else {
        cout << "Error: Invalid choice." << endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

void printMatrix(int** matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void shiftRows(int** matrix, int numRows, int numCols, int numShifts, bool toRight) {
    for (int i = 0; i < numRows; ++i) {
        int* tempRow = new int[numCols];
        for (int j = 0; j < numCols; ++j) {
            int newIdx = toRight ? (j + numShifts) % numCols : (j - numShifts + numCols) % numCols;
            tempRow[newIdx] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = tempRow;
    }
}

void shiftColumns(int** matrix, int numRows, int numCols, int numShifts, bool down) {
    for (int j = 0; j < numCols; ++j) {
        int* tempColumn = new int[numRows];
        for (int i = 0; i < numRows; ++i) {
            int newIdx = down ? (i + numShifts) % numRows : (i - numShifts + numRows) % numRows;
            tempColumn[newIdx] = matrix[i][j];
        }
        for (int i = 0; i < numRows; ++i) {
            matrix[i][j] = tempColumn[i];
        }
        delete[] tempColumn;
    }
}

int main() {
    const int numRows = 3;
    const int numCols = 4;

    int** myMatrix = new int* [numRows];
    for (int i = 0; i < numRows; ++i) {
        myMatrix[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) {
            myMatrix[i][j] = i * numCols + j + 1;
        }
    }

    cout << "Initial matrix:" << endl;
    printMatrix(myMatrix, numRows, numCols);

    shiftRows(myMatrix, numRows, numCols, 1, true);
    cout << "\nMatrix after cyclic shift of rows by 1 to the right:" << endl;
    printMatrix(myMatrix, numRows, numCols);

    shiftColumns(myMatrix, numRows, numCols, 2, true);
    cout << "\nThe matrix after cyclically shifting the columns down by 2:" << endl;
    printMatrix(myMatrix, numRows, numCols);

    for (int i = 0; i < numRows; ++i) {
        delete[] myMatrix[i];
    }
    delete[] myMatrix;

    return 0;
}


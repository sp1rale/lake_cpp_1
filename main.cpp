#include <iostream>
using namespace std;

void addRowToEnd(int**& array, int& numRows, int numCols, int* newRow){
    int newNumRows = numRows + 1;
    int** newArray = new int* [newNumRows];

    for (int i = 0; i < numRows; ++i) {
        newArray[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) {
            newArray[i][j] = array[i][j];
        }
    }

    newArray[numRows] = newRow;

    for (int i = 0; i < numRows; ++i) {
        delete[] array[i];
    }
    delete[] array;
    array = newArray;
    numRows = newNumRows;
}

int main() {
    const int numCols = 3;  
    int numRows = 2;        
    int** myArray = new int* [numRows];
    for (int i = 0; i < numRows; ++i) {
        myArray[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) {
            myArray[i][j] = i * numCols + j + 1;
        }
    }

    cout << "Initial array:" << endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }

    int* newRow = new int[numCols] {7, 8, 9};
    addRowToEnd(myArray, numRows, numCols, newRow);

    cout << "\nArray after adding row:" << endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < numRows; ++i) {
        delete[] myArray[i];
    }
    delete[] myArray;
    delete[] newRow;

    return 0;
}


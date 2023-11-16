#include <iostream>
using namespace std;

void deleteRow(int**& array, int& numRows, int numCols, int rowToDelete) {
    if (rowToDelete < 0 || rowToDelete >= numRows) {
        cout << "Invalid row number. Row does not exist." << endl;
        return;
    }

    int newNumRows = numRows - 1;

    int** newArray = new int* [newNumRows];

    for (int i = 0, newRow = 0; i < numRows; ++i) {
        if (i != rowToDelete) {
            newArray[newRow] = new int[numCols];
            for (int j = 0; j < numCols; ++j) {
                newArray[newRow][j] = array[i][j];
            }
            ++newRow;
        }
    }

    for (int i = 0; i < numRows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    array = newArray;

    numRows = newNumRows;
}

int main() {
    const int numCols = 3;  
    int numRows = 3;      

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

    int rowToDelete = 1; 
    deleteRow(myArray, numRows, numCols, rowToDelete);

    cout << "\nArray after deleting row " << rowToDelete << ":" << endl;
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

    return 0;
}

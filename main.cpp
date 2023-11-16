#include <iostream>
using namespace std;

void deleteColumn(int**& array, int numRows, int& numCols, int columnToDelete) {
    if (columnToDelete < 0 || columnToDelete >= numCols) {
        cout << "Invalid column number." << endl;
        return;
    }

    int newNumCols = numCols - 1;

    int** newArray = new int* [numRows];

    for (int i = 0; i < numRows; ++i) {
        newArray[i] = new int[newNumCols];
        for (int j = 0, newCol = 0; j < numCols; ++j) {
            if (j != columnToDelete) {
                newArray[i][newCol] = array[i][j];
                ++newCol;
            }
        }
    }

    for (int i = 0; i < numRows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    array = newArray;

    numCols = newNumCols;
}

int main() {
    const int numRows = 3;  
    int numCols = 3;        
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

    int columnToDelete = 1;  
    deleteColumn(myArray, numRows, numCols, columnToDelete);

    cout << "\nThe array after removing the column " << columnToDelete << ":" << endl;
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


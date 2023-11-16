#include <iostream>
using namespace std;

void addColumnToPosition(int**& array, int numRows, int& numCols, int* newColumn, int position) {
    if (position < 0 || position > numCols) {
        cout << "Invalid column position. Column cannot be added." << endl;
        return;
    }

    int newNumCols = numCols + 1;

    int** newArray = new int* [numRows];

    for (int i = 0; i < numRows; ++i) {
        newArray[i] = new int[newNumCols];
        for (int j = 0, newCol = 0; j < newNumCols; ++j) {
            if (j == position) {
                newArray[i][j] = newColumn[i];
            }
            else {
                newArray[i][j] = array[i][newCol];
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

    int* newColumn = new int[numRows] {7, 8, 9};
    int positionToAdd = 1; 
    addColumnToPosition(myArray, numRows, numCols, newColumn, positionToAdd);

    cout << "\nArray after adding a column per position " << positionToAdd << ":" << endl;
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

    delete[] newColumn;

    return 0;
}

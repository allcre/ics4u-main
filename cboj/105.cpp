// Allison Cretel 
// ICS4U-02
// 20/10/22
 
#include <iostream>
using namespace std;

void q1a() {
    int row, column;

    int **matrix;
    cout << "rows: ";
    cin >> row;

    cout << "columns: ";
    cin >> column;

    matrix = new int *[row];

    for (int i = 0; i < row; ++i)
        matrix[i]= new int[column];

    cout << "elements of array: ";

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cin >> matrix[i][j]; 
    } 

    for (int k = 0; k < row; k++) {
        for (int l = 0; l < column; l++) 
            cout << matrix[k][l] << ' ';
        cout << "\n";
    }

    for (int m = 0; m < row; m++)
        delete[] matrix[m];
    
    delete[] matrix;
}

void q1b() {
    int row, column;
    int **matrix;
    float sum = 0;
    
    cout << "rows: ";
    cin >> row;
    cout << "columns: ";
    cin >> column;

    matrix = new int *[row];

    for (int i = 0; i < row; i++) 
        matrix[i] = new int[column];
    
    for (int j = 0; j < row; j++) {
        for (int k = 0; k < column; k++) {
            matrix[j][k] = rand() % 1000 + 1;
            sum += matrix[j][k];
        }
    }

    /*
    prints array
    for (int l = 0; l < row; l++) {
        for (int m = 0; m < column; m++)
            cout << matrix[l][m] << ' ';
        cout << "\n";
    }*/

    cout << "average: " << sum / (row * column) << endl;

    for (int m = 0; m < row; m++) {
        delete[] matrix[m];
    }

    delete[] matrix;
}

int main() {
    q1a();
    q1b();
    return 0;
}
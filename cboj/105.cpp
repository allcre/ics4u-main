// Allison Cretel 
// ICS4U-02
// 15/10/22
 
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
        cout << "\n";
        for (int l = 0; l < column; l++) 
            cout << matrix[k][l] << ' ';
    }

    for (int m = 0; m < row; m++)
        delete[] matrix[m];
    
    delete[] matrix;
}

int main() {
    q1a();
    return 0;
}
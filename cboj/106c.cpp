// Allison Cretel 
// ICS4U-02
// 23/10/22

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int size, sum;

    cin >> size >> sum;

    int arr[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) 
            arr[i][j] = 0;
    }

    int irow = 0; 
    int icol = floor(size/2);
    int row, col = 0;

    int u = sum/size - size*size/2 + 0.5; // first number in square
    arr[irow][icol] = u;

    for (int i = u + 1; i < size*size + u + 1; i++) {
        row = irow - 1;
        col = icol + 1;

        if (row < 0)
            row =  size - 1;
        
        if (col > size - 1)
            col = 0;
        
        if (arr[row][col] == 0)
            arr[row][col] = i;
        else if (arr[row][col] != 0) {
            row = irow + 1;
            col = icol;
            arr[row][col] = i;
        } 

        irow = row;
        icol = col;          
    }

    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            cout << arr[j][k] << ' ';
        }
        cout << endl;
    }

    return 0;
}
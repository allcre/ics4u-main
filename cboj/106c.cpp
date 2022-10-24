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

    arr[irow][icol] = 1;

    for (int i = 2; i <= size*size; i++) {
        irow -= 1; 
        icol += 1;

        if (irow < 0)
            irow =  size - 1;
        
        if (icol > size - 1)
            icol = 0;
        
        if (arr[irow][icol] == 0)
            arr[irow][icol] = i;
        else if (arr[irow][icol] != 0) {
            irow += 2;
            icol -= 1;
            arr[irow][icol] = i;
        }           
    }

    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            cout << arr[j][k] << ' ';
        }
        cout << endl;
    }

    return 0;
}
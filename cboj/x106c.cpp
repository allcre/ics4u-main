// Allison Cretel 
// ICS4U-02
// 23/10/22

// algorthim from https://www.oddmagicsquares.com/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int size, sum = 0;

    cin >> size >> sum;

    int arr[size][size];
    int arr1[size][size];
    int arr2[size][size];

    int u = sum/size - size*size/2 + 0.5; // first number in square

    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = u;
            arr1[i][j] = u;
            arr2[i][j]= u;
            u++;
       }
    }

    // shifting top rows right
    for (int i = 1; i <= floor(size/2); i++) {
        for (int j = 0; j < size; j++) {
            int x = j - i;
            if (x < 0)
                x += size;
            
            arr1[i-1][x] = arr[i-1][j];
        }
    }

    // shifting bottom rows left
    int row = size - 1;
    for (int i = 1; i <= floor(size/2); i++) {
        for (int j = 0; j < size; j++) {
            int x = j + i;
            if (x >= size)
                x -= size;
            
            arr1[row][x] = arr[row][j];
        }
        row--;
    }

    //shifting left columns up
    for (int j = 1; j <= floor(size/2); j++) {
        for (int i = 0; i < size; i++) {
            int x = i - j;
            if (x < 0)
                x += size;

            arr2[x][j-1] = arr1[i][j-1];
        }
    }

    //shifting right columns down
    int col = size - 1;
    for (int j = 1; j <= floor(size/2); j++) {
        for (int i = 0; i < size; i++) {
            int x = i + j;
            if (x >= size)
                x -= size;
            
            arr2[x][col] = arr1[i][col];
        }
        col--;
    }


    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j++) {
            cout << arr2[i][j] << ' ';
       }
       cout << endl;
    }

    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int start, end;
    cin >> start >> end;

    int difference = end - start;
    
    if (difference == 0) {
        if (start < 10) 
            cout << ' ' << start;
        else 
            cout << start;
        return 0;
    }

    int rows = floor(sqrt(difference)) + 1;

    int sol1 = (1 + sqrt(1 + 4 * difference)) / 2;
    int sol2 = (1 - sqrt(1 + 4 * difference)) / 2;

    int cols = max(sol1, sol2);

    int arr[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
    }

    int irow;
    if (rows % 2 == 0)
        irow = rows/2 - 1;
    else 
        irow = floor(rows/2);

    int icol;
    if (cols % 2 == 0)
        icol = cols/2 - 1;
    else 
        icol = floor(cols/2);

    arr[irow][icol] = start;

    int n = start + 1;
    int x = 1;

    while (true) {
        for (int i = 0; i < x; i++) {
            arr[irow+1][icol] = n;
            irow++;
            n++;

            if (n > end)
                goto next;
        }
        
        for (int j = 0; j < x; j++) {
            arr[irow][icol+1] = n;
            icol++;
            n++;

            if (n > end)
                goto next;
        }
        x++;

        for (int k = 0; k < x; k++) {
            arr[irow-1][icol] = n;
            irow--;
            n++;

            if (n > end)
                goto next;
        }

        for (int l = 0; l < x; l++) {
            arr[irow][icol-1] = n;
            icol--;
            n++;

            if (n > end)
                goto next;
        }
        x++;
    } 

    next: 
    for (int m = 0; m < rows; m++) {
        for (int n = 0; n < cols; n++) {
            if (arr[m][n] >= 10)
                cout << arr[m][n];
            else if (arr[m][n] != 0)
                cout << ' ' << arr[m][n];
            else
                cout << "  ";
            
            if (n != cols - 1)
                cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
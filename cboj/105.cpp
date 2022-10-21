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

    for (int m = 0; m < row; m++)
        delete[] matrix[m];

    delete[] matrix;
}

void q1c() {
    int size;
    
    cout << "size: ";
    cin >> size;

    int **matrix = new int *[size];

    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];

    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            matrix[j][k] = rand() % 1000 + 1;
            if (j == k) 
                cout << matrix[j][k] << " ";
        }
    }

    for (int m = 0; m < size; m++)
        delete[] matrix[m];
    
    delete[] matrix;
}

// For this question, I declared two 2d arrays with different widths and lengths. 
// The new 3rd array containing the elements from the first and second array has the same width as the first array. 
void q2() {
    int row1, row2, row3, column1, column2, column3;

    cout << "\nrows of first array: ";
    cin >> row1;
    cout << "columns of first array: ";
    cin >> column1;

    int **matrix1 = new int *[row1];

    for (int i = 0; i < row1; i++)
        matrix1[i] = new int[column1];

    cout << "first array:" << endl;

    for (int j = 0; j < row1; j++) {
        for (int k = 0; k < column1; k++) {
            matrix1[j][k] = rand() % 1000 + 1;
            cout << matrix1[j][k] << ' ';
        }
        cout << "\n";
    }

    cout << "rows of 2nd array: ";
    cin >> row2;
    cout << "columns of 2nd array: ";
    cin >> column2;

    int **matrix2 = new int *[row2];

    for (int l = 0; l < row2; l++)
        matrix2[l] = new int[column2];

    cout << "second array:" << endl;
    for (int m = 0; m < row2; m++) {
        for (int n = 0; n < column2; n++) {
            matrix2[m][n] = rand() % 1000 + 1;
            cout << matrix2[m][n] << ' ';
        }
        cout << "\n";
    }

    column3 = column1;
    row3 = ((row1 * column1) + (row2 * column2)) / column3 + 1;

    int **matrix3 = new int *[row3];

    for (int o = 0; o < row3; o++) 
        matrix3[o] = new int [column3];

    cout << "\n3rd array:" << endl;

    for (int p = 0; p < row1; p++) {
        for (int q = 0; q < column1; q++) {
            matrix3[p][q] = matrix1[p][q];
            cout << matrix3[p][q] << ' ';
        }
        cout << "\n";
    }

    int q = row1;
    int r = 0;
    int x = 0;

    for (int s = 0; s < row2; s++) {
        for (int t = 0; t < column2; t++) {
            matrix3[q][r] = matrix2[s][t];

            cout << matrix3[q][r] << ' ';
            x++;
            r++;

            if (r % column3 == 0) {
                r = 0;
                q++;
                cout << "\n";
            }

        }
    }

    for (int u = 0; u < row1; u++)
        delete[] matrix1[u];
    for (int v = 0; v < row2; v++)
        delete[] matrix2[v];
    for (int w = 0; w < row3; w++)
        delete[] matrix3[w];

    delete[] matrix1;
    delete[] matrix2;
    delete[] matrix3;
}

// Q3

void modifyArray(int b[], int ArraySize) {
    for (int i = 0; i < ArraySize; i++) {
        b[i] = 2*b[i];
        cout << b[i] << ' ';
    }
}

void modifyElement(int a) {
    cout << 2*a << endl;
}

int main() {
    q1a();
    q1b();
    q1c();
    q2();

    // Q3
    int element[5];
    for (int index = 0; index <= 4; index++)
        element[index] = index;

    cout << "\nEffects of passing entire array call by reference\n\n";
    cout << "Value of the original array is \n";
    
    for (int x = 0; x <= 4; x++)
        cout << element[x] << " ";
    cout << endl;
    
    modifyArray (element, 5);

    cout << endl << endl;

    cout << "Effects of passing array element call-by-value\n\n";
    cout << "The value of element[3] is " << element[3] << endl;
    
    modifyElement(element[3]);
    
    cout << "The value of element[3] is " << element[3] << endl;

    return 0;
}
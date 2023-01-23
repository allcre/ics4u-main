// Allison Cretel
// ICS4U-02

#include <iostream>
using namespace std;

void q4b(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    int pos_min, temp;
    for (int i = 0; i < n; i++) {
        pos_min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[pos_min]) {
                pos_min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[pos_min];
        arr[pos_min] = temp;

        for (int k = 0; k < n; k++) {
            cout << arr[k] << ' ';
        }
        cout << endl;
    }
}

void q5(int arr[], int n, int k) {
    int pos_max, temp;
    int counter = 0;
    for (int i = n-1; i > 0; i--) {
        pos_max = i;
        for (int j = 0; j <= i; j++) {
            if (arr[j] > arr[pos_max]) {
                pos_max = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[pos_max];
        arr[pos_max] = temp;
        counter++;

        if (counter == k) {
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Q1" << endl;
    cout << "Robert Brian Victor David Scott" << endl;
    cout << "Robert Brian Scott David Victor" << endl;
    cout << "Robert Brian David Scott Victor" << endl;
    cout << "David Brian Robert Scott Victor" << endl;
    cout << "Brian David Robert Scott Victor" << endl;

    /*
    2. the array would be sorted in descending order
    3. a. add an if statement to check if arr[i] is equal to the largest value found
       b. this adds an unecessary step to the algorithm and would not be worth the increase in runtime as this case is rare
    */

    cout << "Q4" << endl;
    cout << "8 9 6 1 2 4" << endl;
    cout << "1 9 6 8 2 4" << endl;
    cout << "1 2 6 8 9 4" << endl;
    cout << "1 2 4 8 9 6" << endl;
    cout << "1 2 4 6 9 8" << endl;
    cout << "1 2 4 6 8 9" << endl;

    cout << "Q5" << endl;
    q5(a, n, k);

    return 0;
}
// Allison Cretel
// ICS4U-02
// 22/01/23

#include <iostream>
#include <algorithm>
using namespace std;

int* createRndArray(int size, int high, int low) {
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (high - low + 1) + low;
    }
    
    return arr;
}

void print(int* arr, int min, int max) {
    for (int i = min; i < max; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int linearSearch(int arr[], int size, int target) {
    cout << "Linear Search" << endl;
    for (int i = 0; i < size; i++) {
        print(arr, i, size);
        if (arr[i] == target) {
            cout << "found at index " << i << endl;
            return i;
        }
    }
    cout << "not found" << endl;
    return -1;
}

int binarySearch(int arr[], int size, int target) {
    cout << "\nBinary Search" << endl;
    int min = 0;
    int max = size - 1;
    int mid;
    while (min <= max) {
        mid = (min + max + 1) / 2;
        print(arr, min, max + 1);
        //cout << min << ' ' << mid << ' ' << max << endl;
        if (arr[mid] == target) {
            if (mid != max)
                cout << target << endl;
                
            cout << "found at index " << mid << endl;
            return mid;
        } 
        else if (arr[mid] < target) {
            min = mid + 1;
        } 
        else {
            max = mid - 1;
        }
    }
    cout << "not found" << endl;
    return -1;
}

int main() {

    createRndArray(5, 100, 10);

    int n, x;
    cin >> n;
    cin >> x;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    linearSearch(arr, n, x);
    binarySearch(arr, n, x);

    return 0;
}
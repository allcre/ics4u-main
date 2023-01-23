// Allison Cretel
// ICS4U-02

#include <iostream>
#include <string>
using namespace std;

/*
1. 
6 2 8 3 1 7 4
2 6 8 3 1 7 4
2 6 8 3 1 7 4
2 3 6 8 1 7 4
1 2 3 6 8 7 4
1 2 3 6 7 8 4
1 2 3 4 6 7 8

2. 
To sort the elements in descending order, the condition in the while loop would be changed to arr[current] > arr[next]
If the current element is smaller than the next then the elements would be swapped.  
*/

void q1() {
    int current;
    int arr[7] = {6,2,8,3,1,7,4};

    
    for (int j = 0; j < 7; j++) {
        current = j;
        while (current > 0 && arr[current] < arr[current - 1]) {
            swap(arr[current], arr[current - 1]);
            current--;
        }
        for (int i = 0; i < 7; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
}

void planets() {
    string arr[8] = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune"};
    
    int current;
    string temp; 

    for (int j = 0; j < 8; j++) {
        cout << arr[j] << ' ';
    }
    cout << endl;

    for (int i = 1; i < 8; i++) {
        current = i;
        while (current > 0 && arr[current] < arr[current - 1]) {
            temp = arr[current];
            arr[current] = arr[current - 1];
            arr[current - 1] = temp;
            current--;
        }
        for (int j = 0; j < 8; j++) {
            cout << arr[j] << ' ';
        }
        cout << endl;
    }        
}

float median() {
    int n;
    cin >> n;
    float arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        int current = i;
        while (current > 0 && arr[current] < arr[current - 1]) {
            float temp = arr[current];
            arr[current] = arr[current - 1];
            arr[current - 1] = temp;
            current--;
        }
    }
    
    if (n % 2 == 0) {
        return (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
    } else {
        return (arr[n / 2]);
    }
}

int main() {
    float n = median();
    cout << "Q1" << endl;
    q1();

    cout << "Q3" << endl;
    planets();

    cout << "Q4" << endl << n << endl;
    return 0;
}
// Allison Cretel 
// ICS4U-02
// 14/10/22
 
#include <iostream>
#include <cstdlib>
using namespace std;

void q1a();
void q1b();
void q1c();
void q1d();

int main() {
    q1a();
    q1b();
    q1c();
    
    return 0;
}

void q1a() {
    int length;
    int *ArrayPtr;

    cout << "Please enter the length of the array" << endl;
    cin >> length;

    ArrayPtr = new int[length];

    cout << "Please enter the elements of the array" << endl;

    for (int i = 0; i < length; i++)
        cin >> ArrayPtr[i];

    for (int i = 0; i < length; i++)
        cout << ArrayPtr[i] << ' ';

    delete[] ArrayPtr;
}

void q1b() {
    int length;
    int *arrP;

    cout << "\nEnter length of array: ";
    cin >> length;

    arrP = new int[length];

    cout << "\nEnter elements of the array:" << endl;
    
    for (int i = 0; i < length; i++)
        cin >> arrP[i];
    
    for (int i = length -1; i >= 0; i--)
        cout << arrP[i] << ' ';

    delete[] arrP;
}

void q1c() {
    int length;
    int *arrP;
    int sum = 0;

    cout << "\nLength of array:" << endl;
    cin >> length;

    arrP = new int[length];

    for (int i = 0; i < length; i++)
        arrP[i] = rand() % 50 + 1;

    for (int i = 0; i < length; i++)
        sum += arrP[i];

    cout << "\n" << sum << endl;
}

void q1d() {
    
}
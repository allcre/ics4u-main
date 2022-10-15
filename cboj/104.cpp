// Allison Cretel 
// ICS4U-02
// 15/10/22
 
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
    q1d();
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

    cout << "Enter elements of the array:" << endl;
    
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

    cout << sum << endl;

    delete[] arrP;
}

void q1d() {
    int l1, l2;
    int *p1, *p2, *p3;

    cout << "Length of first array: ";
    cin >> l1;
    cout << "Length of second array: ";
    cin >> l2;

    p1 = new int[l1];
    p2 = new int[l2];
    p3 = new int[l1 + l2];

    cout << "Enter first array elements: " << endl;
    for (int i = 0; i < l1; i++)
        cin >> p1[i];
    
    cout << "Enter second array elements: " << endl;
    for (int i = 0; i < l2; i++)
        cin >> p2[i];

    for (int i = 0; i < l1; i++)
        p3[i] = p1[i];
    
    for (int i = 0; i < l2; i++)
        p3[i + l1] = p2[i];
    
    for (int i = 0; i < l1+l2; i++)
        cout << p3[i] << ' ';
    
    delete[] p1;
    delete[] p2;
    delete[] p3;
}
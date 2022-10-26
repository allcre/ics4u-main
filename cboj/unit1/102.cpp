// Allison Cretel 
// ICS4U-02
// 06/10/22

#include <iostream>
using namespace std;

int main() {

    // Q1
    int number;
    int *pnumber;

    number = 123;
    pnumber = &number;

    cout << number << ", " << &number << ", " << pnumber << ", " << *pnumber << endl;
    
    // Q2
    int num1 = 50;
    int num2 = 100;

    int *pnum = NULL;
    pnum = &num1;
    *pnum += 10;

    cout << num1 << ' ' << pnum << endl;

    pnum = &num2;
    *pnum *= 10;
    num1 = *pnum;

    cout << num1 << ' ' << pnum << ' ' << *pnum << endl;

    // Q3
    double value1 = 200000;
    double value2;

    double *lPtr;
    lPtr = &value1;
    cout << *lPtr << endl;

    value2 = *lPtr;
    cout << value2 << endl;
    cout << &value1 << endl;
    cout << lPtr << endl;
    // g) the value printed is the same as the address of value1 as the pointer was never reassigned to a different variable

    return 0;
}
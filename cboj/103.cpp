// Allison Cretel 
// ICS4U-02
// 06/10/22

#define _USE_MATH_DEFINES // for pi
 
#include <cmath>
#include <iostream>
using namespace std;

// Q1
void cubeByPointer(double *ptr) {
    *ptr = *ptr * *ptr * *ptr;
    cout << *ptr << endl;
}

// Q2
void sumTwoInt(int *num1, int *num2) {
    cout << *num1 + *num2 << endl;
}

// Q3
void circle(double *radPtr, double *areaPtr, double *circPtr) {
    *areaPtr = *radPtr * *radPtr * M_PI;
    *circPtr = *radPtr * 2 * M_PI;
}

// Q4
bool quadEquation (double a, double b, double c, double *sol1, double *sol2) {
    *sol1 = (0-b + sqrt(b*b - 4*a*c)) / (2*a);
    *sol2 = (0-b - sqrt(b*b - 4*a*c)) / (2*a);

    if (!isnan(*sol1) && !isnan(*sol2))
        return true;
    else 
        return false;
}

int main() {

    // Q1
    double num = 5.5;
    double *numPtr = &num;
    cubeByPointer(numPtr);
    
    // Q2
    int num1 = 10;
    int num2 = 20;
    int *ptr1 = &num1;
    int *ptr2 = &num2;
    sumTwoInt(ptr1, ptr2);

    // Q3
    double radius = 4;
    double area = 0.0;
    double circ = 0.0;
    double *radPtr = &radius;
    double *areaPtr = &area;
    double *circPtr = &circ;
    circle(radPtr, areaPtr, circPtr);
    cout << "Area is: " << area << endl;
    cout << "Circumference is: " << circ << endl;

    // Q4
    double a = 3;
    double b = 6;
    double c = 3;
    double sol1 = 0.0;
    double sol2 = 0.0;
    double *sol1Ptr = &sol1;
    double *sol2Ptr = &sol2;

    if (quadEquation(a, b, c, sol1Ptr, sol2Ptr)) {
        if (sol1 == sol2)
            cout << "The root is " << sol1 << endl;
        else 
            cout << "The roots are " << sol1 << " and " << sol2 << endl;
    }
    else
        cout << "No roots" << endl;

    return 0;
}
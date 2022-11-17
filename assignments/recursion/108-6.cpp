#include <iostream>
using namespace std;

// initializes an array with whole numbers 1 through N
int init(int a[], int n) {
    if (n == 0)
        a[0] = 1; 
    else
        a[n] = 1 + init(a, n - 1);
    
    return a[n];
}

// find greatest common denominator
long gcd(long x, long y) {
    if (y == 0)
        return x;
    else 
        return gcd(y, x % y);
}

// the lcm of 2 numbers is x*y / gcd(x,y), find fractorial from lcm of all numbers 1 - N
long fractorial(int a[], int i) {
    if (i == 0)
        return a[0];
    else {
        long x = a[i];
        long y = fractorial(a, i - 1);
        return (x * y / gcd(x, y));
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];

    init(a, n);

    int size = sizeof(a)/sizeof(a[0]);
    cout << fractorial(a, size - 1) << endl;

    return 0;
}
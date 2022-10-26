#include <iostream>
using namespace std;

// ex 1
int power(int base, int e) {
    if (e == 0)
        return 1;
    else 
        return base * power(base, e-1);
}

//ex 2
int fib (int n) {
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else 
        return fib(n - 1) + fib(n - 2);
}

// ex3
void print_array_rec(int a[], int length) {
    if (length == 0)
        cout << "\t";

    else 
        print_array_rec(a, length - 1);

    cout << a[length] << "\t";
}

int main() {
    cout << power(2, 4) << endl;
    cout << fib(10) << endl;

    int arr[5] = {0, 1, 2, 3, 4};
    print_array_rec(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}
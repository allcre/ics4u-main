// Allison Cretel
// ICS4U-02
// 27/10/22

#include <iostream>
#include <cmath>
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
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else 
        return fib(n - 1) + fib(n - 2);
}

// ex 3
void print_array_rec(int a[], int length) {
    if (length == 0)
        cout << "\t";

    else 
        print_array_rec(a, length - 1);

    cout << a[length] << "\t";
}

// ex 4a
void init_array(int n, int a[]) {
    if (n == 0) {
        a[0] = rand() % 50 + 1;
    }
    else {
        a[n-1] = rand() % 50 + 1;
        init_array(n - 1, a);
    }        
}


// ex 4b
void twopower(int length, int *arr) {
    if (length == 0)
        arr[0] = 1;
    else {
        arr[length] = 2 * power(2, length - 1);
        twopower(length - 1, arr);
    }
}

// ex 4c
int sum(int length, int *arr) {
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += arr[i];

    return sum;
}

// ex 4d
int recursive_sum(int length, int *arr) {
    if (length == 0)
        return 0;
    else 
        return recursive_sum(length - 1, arr) + arr[length - 1];
}

// ex 4e
int largest(int length, int* arr){
    int big = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] > big)
            big = arr[i];
    }
    
    return big;
}

// ex 4f
int recursive_largest(int length, int* arr) {
    if (length == 0)
        return arr[0];
    else
        return max(recursive_largest(length - 1, arr), arr[length - 1]);
}

// ex 5
double bday(int students) {
    double prod = 1;

    for (float n = 364; n > 365 - students; n--)
        prod *= (n / 365);

    return (1 - round(prod * 1000) / 1000);
}

double rec_bday(double students) {
    if (students == 1)
        return 1.0;
    
    return ((365 - (students - 1))/365 * rec_bday(students - 1));
}

int main() {
    cout << power(2, 4) << endl;

    cout << fib(10) << endl;

    int arr[5] = {0, 1, 2, 3, 4};
    print_array_rec(arr, sizeof(arr)/sizeof(arr[0]) - 1);
    cout << endl;

    init_array();

    int length = 5;
    int *arr2 = new int[length];
    twopower(10, arr2);
    for (int i  = 0; i < length; i++)
        cout << arr2[i] << ' ';
    cout << endl;

    cout << sum(length, arr2) << endl;

    cout << recursive_sum(length, arr2) << endl;

    cout << largest(length, arr2) << endl;

    cout << recursive_largest(length, arr2) << endl;

    cout << bday(26) << endl;

    cout << 1 - round(rec_bday(26) * 1000) / 1000 << endl;

    return 0;
}
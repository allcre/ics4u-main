#include <iostream>
#include <cmath>
using namespace std;

double average(int a[], int i) {
    if (i == 1) 
        return a[i - 1];
    else
        return (average(a, i - 1) * (i - 1) + a[i - 1]) / i;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    double ave = floor(average(a, n) * 10) / 10;
    cout << ave << endl;

    return 0;
}
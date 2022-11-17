#include <iomanip>
#include <iostream>
using namespace std;

long double average(int a[], int i) {
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
    
    cout << setprecision(1) << fixed << average(a, n) << endl;

    return 0;
}
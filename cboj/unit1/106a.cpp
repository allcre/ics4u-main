// Allison Cretel 
// ICS4U-02
// 20/10/22

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n+1];

    for (int i = 0; i <= n; i++)
        arr[i] = 1;

    arr[0] = 0;
    arr[1] = 0;

    for (int j = 2; j <= n; j++) {
        if (arr[j] == 1) {
            for (int k = j; k <= n; k += j) {
                if (k % j == 0 && k != j)
                    arr[k] = 0;
            }
        }
    }

    for (int l = 0; l <= n; l++) {
        if (arr[l] == 1)
            cout << l << ' ';
    }

    return 0;
}
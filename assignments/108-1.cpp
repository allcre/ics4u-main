#include <iostream>
using namespace std;

int rec_a(int a) {
    if (a == 1)
        return 3;
    else 
        return (rec_a(a - 1) - 2);
}

int rec_b(int a) {
    if (a == 1)
        return -1;
    else
        return 2 * rec_b(a - 1);
}

int main() {
    int n;
    cin >> n;

    cout << rec_a(n) << endl;
    cout << rec_b(n) << endl;

    return 0;
}
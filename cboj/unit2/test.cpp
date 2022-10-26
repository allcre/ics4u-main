#include <iostream>
using namespace std;

int factorial(int n) {
    //base case: factorial(0) = 1
    if (n == 0)
        return 1;
    //recursive case: factorial(n) = n * factorial(n-1)
    else
        return n * factorial(n-1);
}

int main() {
    cout << factorial(4);
    return 0;
}


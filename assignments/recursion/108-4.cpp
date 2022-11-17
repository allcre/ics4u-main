#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string decimalToBinary(int n, string x) {
     if (n == 0) {
        if (x.empty())
            return "0";
        else 
            return x;
     }
     else {
        x = to_string(n % 2) + x;
        n = floor(n / 2);
        return decimalToBinary(n, x);
     }

}

int main() {
    int n;
    cin >> n;

    string x;
    cout << decimalToBinary(n, x) << endl;
    
    return 0;
}
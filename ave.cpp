#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n;
    float ave = 0;

    cin >> n;

    if (n == 1) {
        cin >> ave;
        cout << ave;
        return 0;
    }

    int nums[n];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        ave += (nums[i] - ave) / (i + 1);
    }

    ave = round(ave * 10) / 10;

    cout << ave;
}
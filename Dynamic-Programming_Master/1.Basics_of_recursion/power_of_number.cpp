#include <bits/stdc++.h>
using namespace std;

int power_number(int n, int p) {
    if (p == 1) {
        return n;
    }
    return n * power_number(n, p - 1);
}

int power_number_opt(int n, int p) {
    if (p == 1) {
        return n;
    }
    int subPower = power_number_opt(n, p / 2);
    int squareSubPower = subPower * subPower;

    if (p & 1) {
        return n * squareSubPower;
    }
    return squareSubPower;
}

int main() {
    int n = 2;
    int p = 10;
    cout << power_number(n, p) << endl;
    cout << power_number_opt(n, p) << endl;
}
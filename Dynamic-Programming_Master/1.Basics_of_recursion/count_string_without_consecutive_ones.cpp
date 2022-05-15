#include <bits/stdc++.h>
using namespace std;

int NofBinaryStrings(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 2;
    }

    return NofBinaryStrings(n - 1) + NofBinaryStrings(n - 2);
}

int main() {
    int n = 5;
    cout << NofBinaryStrings(n);
}
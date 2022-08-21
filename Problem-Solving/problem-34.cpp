// Z Sequence

#include <bits/stdc++.h>
using namespace std;

int Z_seq(int p, int q, int n) {
    int Zi;
    if (n == 1) {
        return p * (__builtin_popcount(2)) + q;
    }
    Zi = p * (__builtin_popcount(Z_seq(p, q, n-1))) + q;

    return Zi;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p, q, n;
        cin >> p >> q >> n;
        cout << __builtin_popcount(Z_seq(p, q, n)) << endl;
    }
}
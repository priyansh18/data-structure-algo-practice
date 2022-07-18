#include <bits/stdc++.h>
using namespace std;


int solve(string A) {
    int n = A.length();
    int v = 0;
    int c = 0;
    int M = 1e9 + 7;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 'a' or A[i] == 'e' or A[i] == 'i' or A[i] == 'o' or
            A[i] == 'u') {
            if (c != 0) ans += c;
            v++;
        } else {
            if (v != 0) ans += v;
            c++;
        }
    }

    return ans%M;
}

int main() {
    string A = "aba";
    cout << solve(A);
}
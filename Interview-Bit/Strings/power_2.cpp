#include <bits/stdc++.h>
using namespace std;

int power(string A) {
    int k = A.length();
    long long n = 0;
    int p = 0;
    for (int i = k - 1; i >= 0; i--) {
        n += pow(10, p) * (A[i] - '0');
        p++;
    }
    if (n == 0) return 0;
    return (n & (n - 1)) == 0;
}

int main() {
    string A = "5";
    cout << power(A);
}

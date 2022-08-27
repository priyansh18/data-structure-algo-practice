// Kth Root of number

#include <bits/stdc++.h>
using namespace std;

double multiply(double mid, int n) {
    double ans = 1.0;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
    }
    return ans;
}

double kthRoot(int n, int k) {
    double low = 1;
    double high = k;
    double eps = 1e-9;
    double answer = 0;
    while ((high - low) > eps) {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) <k)
            low = mid;
        else
            high = mid;
    }
    // cout << pow(k, (double)(1.0 / (double(n))));
    return low;
}

int main() {
    int n = 3;
    int k = 29;
    cout << kthRoot(n, k);
}
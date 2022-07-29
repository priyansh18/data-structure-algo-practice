#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = A[i - 1] + prefix[i - 1];
    }
    int maxEl = INT_MIN;
    for (int i = 0; i <= B; i++) {
        int start = prefix[i];
        int end = prefix[n] - prefix[n - B + i];
        maxEl = max(maxEl, start + end);
    }

    return maxEl;
}

int main() {
    vector<int> A = {5, -2, 3, 1, 2};
    cout << solve(A, B) << endl;
    int B = 3;
}
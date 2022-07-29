#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    int n = A.size();
    vector<int> rightMax(n);
    rightMax[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], A[i]);
    }
    set<int> s;
    s.insert(A[0]);
    int maxSum = INT_MIN;
    for (int i = 1; i < n; i++) {
        s.insert(A[i]);
        auto it = s.find(A[i]);
        if (it != s.begin() and rightMax[i]!=A[i]) maxSum = max(maxSum, (*--it) + A[i] + rightMax[i]);
    }

    return maxSum;
}

int main() {}
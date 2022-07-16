#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int maxVal = INT_MIN;

    for (auto x : A) {
        maxVal = max(x, maxVal);
    }

    int s = 0;
    int e = maxVal;
    int res;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        long remainingSum = 0;
        for (auto x : A) {
            if (x - mid > 0) {
                remainingSum += x - mid;
            }
        }
        if (remainingSum >= B) {
            res = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return res;
}

int main() {
    vector<int> A = {4, 42, 40, 26, 46};
    vector<int> A1 = {20, 15, 10, 17};
    int B = 20;
    int B1 = 7;
    cout << solve(A, B) << endl;
    cout << solve(A1, B1) << endl;
}
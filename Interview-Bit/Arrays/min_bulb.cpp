#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();
    int i = 0;
    int bulbs = 0;
    while (i < n) {
        int left = max(0, i - B + 1);
        int right = min(i + B - 1, n - 1);
        bool bulbFound = false;
        while (right >= left) {
            if (A[right] == 1) {
                bulbFound = true;
                break;
            }
            right--;
        }
        if (!bulbFound) return -1;

        bulbs++;
        i = right + B;
    }

    return bulbs;
}

int main() {
    vector<int> A = {0, 0, 1, 1, 1, 0, 0, 1};
    int B = 3;
    cout << solve(A, B) << endl;
}
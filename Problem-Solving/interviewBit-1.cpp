// Find leaders in an array.
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A) {
    vector<int> result;
    int n = A.size();
    int current_max = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        if (A[i] > current_max) {
            result.push_back(A[i]);
            current_max = A[i];
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    vector<int> nums = {10, 1, 3, 5, 9, 8, 1, 2};
    vector<int> result = solve(nums);
    for (auto x : result) {
        cout << x << ",";
    }
}
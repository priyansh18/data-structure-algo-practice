#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    ans.push_back(A[0]);
    for (int i = 1; i < A.size(); i++) {
        if (ans.back()[1] >= A[i][0]) {
            ans.back()[1] = min(ans.back()[1], A[i][1]);
        } else {
            ans.push_back(A[i]);
        }
    }

    return ans.size();
}

int main() {
    vector<vector<int>> A = {{1, 4}, {2, 3}, {4, 6}, {8, 9}};
    cout << solve(A);
}
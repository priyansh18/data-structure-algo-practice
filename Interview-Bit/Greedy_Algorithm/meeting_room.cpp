#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> x, vector<int> y) { return x[0] < y[0]; }

int solve(vector<vector<int>> &A) {
    sort(A.begin(), A.end());
    priority_queue<int, vector<int>, greater<int>>
        q;  // only end time is sufficient
    q.push(A[0][1]);
    for (int i = 1; i < A.size(); i++) {
        if (q.top() <= A[i][0]) {
            q.pop();
            q.push(A[i][1]);
        } else {
            q.push(A[i][1]);
        }
    }

    return q.size();
}

int main() {
    vector<vector<int>> A = {{0, 14}, {6, 25}, {12, 19}, {13, 19}, {5, 9}};
    cout << solve(A) << endl;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, int B) {
    int n = A.size();
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[A[i]] = i;
    }
    int i = 0;
    while (i < n and B) {
        int x = n - i;
        if (A[i] == x) {
            i++;
            continue;
        } else {
            int locMax = m[x];
            m[A[i]] = locMax;
            swap(A[locMax], A[i]);
            i++;
            B--;
        }
    }

    return A;
}

int main() {
    vector<int> A = {4, 1, 3, 5, 6, 2};
    int B = 3;
    vector<int> result = solve(A, B);
    for (auto x : result) {
        cout << x << ",";
    }
}
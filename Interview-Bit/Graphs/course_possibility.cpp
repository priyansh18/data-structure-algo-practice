
#include <bits/stdc++.h>
using namespace std;

bool cycleDetected(vector<vector<int>> &v, int src, vector<int> &visited,
                   vector<int> &stack) {
    visited[src] = 1;
    stack[src] = 1;
    for (auto nbr : v[src]) {
        if (stack[nbr]) return true;
        if (!visited[nbr]) {
            bool success = cycleDetected(v, nbr, visited, stack);
            if (success) return true;
        }
    }

    stack[src] = 0;
    return false;
}

int solve(int A, vector<int> &B, vector<int> &C) {
    vector<vector<int>> v(A + 1);
    for (int i = 0; i < B.size(); i++) {
        v[B[i]].push_back(C[i]);
    }

    vector<int> visited(A + 1, 0);
    vector<int> stack(A + 1, 0);

    for (int i = 1; i <= A; i++) {
        if (!visited[i]) {
            bool success = cycleDetected(v, i, visited, stack);
            if (success) return false;
        }
    }

    return true;
}

int main() {
    int A = 3;
    vector<int> B = {1, 2, 3};
    vector<int> C = {2, 3, 1};
    cout << solve(A, B, C);
}

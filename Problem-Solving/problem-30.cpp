// Josepheus Problem

#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &dead, int k, int idx, int ans) {
    if (dead.size() == 1) {
        ans = dead[0];
        return ans;
    }

    int deadPerson = (idx + k) % (dead.size());
    dead.erase(dead.begin() + k);
    return helper(dead, k, idx, ans);
}

int lastManLive(int n, int k) {
    vector<int> dead(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        dead[i] = i;
    }
    k = k - 1;
    int ans = -1;
    int idx = 1;
    return helper(dead, k, idx, ans);
}

int main() {
    int n = 40;
    int k = 7;
    cout << lastManLive(n, k);
}
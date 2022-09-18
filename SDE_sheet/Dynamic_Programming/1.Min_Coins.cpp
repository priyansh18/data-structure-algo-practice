#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
int l = coins.size();

bool isPossible(int target, int level) {
    if (target < 0) return false;
    if (level == -1) {
        if (target != 0) return false;
        return true;
    }

    bool ans = false;
    ans |= isPossible(target - coins[level], level);
    ans |= isPossible(target, level - 1);
    return ans;
}
vector<vector<int>> v;
void printSet(int target, int level, vector<int> &res) {
    if (target < 0) return;
    if (level == -1) {
        if (target == 0) {
            v.push_back(res);
            return;
        }
    }
    if (isPossible(target - coins[level], level)) {
        res.push_back(coins[level]);
        printSet(target - coins[level], level, res);
        res.pop_back();
    } 
    
    if (isPossible(target, level - 1)) {
        printSet(target, level - 1, res);
    }
}

void solve() {
    int n;
    cin >> n;
    // cout << isPossible(n, l - 1);
    vector<int> res;
    printSet(n, l - 1, res);

    // freopen("output.txt","w",stdout);
    for (auto x : v) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
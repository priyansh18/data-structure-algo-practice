#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> nums;

int countLIS() {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (temp.empty() or temp.back() < nums[i]) {
            temp.push_back(nums[i]);
        } else {
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            *it = nums[i];
        }
    }

    return temp.size();
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        nums.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << countLIS() << endl;
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
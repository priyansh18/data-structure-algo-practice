#include <bits/stdc++.h>
using namespace std;

string solve(string A) {
    queue<char> q;
    vector<int> freq(26, 0);
    string ans;
    for (auto x : A) {
        if (freq[x - 'a'] == 0) {
            freq[x - 'a']++;
            q.push(x);
            ans += q.front();
        } else {
            freq[x - 'a'] += 1;
            while (!q.empty() and freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            if (q.empty())
                ans += '#';
            else
                ans += q.front();
        }
    }

    return ans;
}

int main() {
    string s = "abadbc";
    cout << solve(s) << endl;
}
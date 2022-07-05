// Sort Character by frequency

#include <bits/stdc++.h>
using namespace std;

class Compare {
   public:
    bool operator()(pair<char, int> A, pair<char, int> B) {
        return A.second < B.second;
    }
};

class Solution {
   public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> m;
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> p;

        for (auto x : m) {
            p.push({x.first, x.second});
        }

        string output = "";
        while (!p.empty()) {
            int val = p.top().second;
            while (val--) {
                output += p.top().first;
            }
            p.pop();
        }

        return output;
    }
};

int main() {
    Solution s;
    string str = "priyanshsinghal";
    cout << s.frequencySort(str);
}
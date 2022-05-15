// Partition Labels.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]] = i;
        }

        for (auto x : m) {
            cout << x.first << " and " << x.second << endl;
        }

        int i = 0;
        int j = m[s[0]];
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] > j) {
                j = m[s[i]];
            }

            if (i == j) {
                result.push_back(j - start + 1);
                start = j + 1;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    string str = "ababcbacadefegdehijhklij";
    vector<int> result = s.partitionLabels(str);
    for (auto x : result) {
        cout << x << ",";
    }
}
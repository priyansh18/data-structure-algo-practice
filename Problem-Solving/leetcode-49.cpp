// Group Anagram

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> m;
        for (auto x : strs) {
            string temp = x;
            sort(temp.begin(), temp.end());
            m[temp].push_back(x);
        }

        for (auto x : m) {
            res.push_back(x.second);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"act", "cat", "tea", "dog", "eat"};
    vector<vector<string>> result = s.groupAnagrams(strs);

    for (auto x : result) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}
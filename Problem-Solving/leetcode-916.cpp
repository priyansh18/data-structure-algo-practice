// Word Subsets

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Word2 Map
        vector<string> result;
        map<char, int> globalMap;

        for (auto x : words2) {
            // Creating new map to store maximum of all words
            map<char, int> localMap;
            for (auto k : x) {
                localMap[k]++;
            }
            // update map depending on current word
            for (auto x : localMap) {
                globalMap[x.first] = max(globalMap[x.first], localMap[x.first]);
            }
        }

        for (auto s : words1) {
            bool flag = true;
            map<char, int> wordMap;
            for (auto x : s) {
                wordMap[x]++;
            }
            for (auto x : globalMap) {
                if (wordMap[x.first] < x.second) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result.push_back(s);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<string> words1 = {"amazon", "apple", "facebook", "google",
                             "leetcode"};
    vector<string> words2 = {"lo", "eo"};
    vector<string> result = s.wordSubsets(words1, words2);
    for (auto x : result) cout << x << ",";
}
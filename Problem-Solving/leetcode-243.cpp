// Shortest word distance

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int shortestDistance(vector<string> &words, string &word1, string &word2) {
        int w1 = -1e9;
        int w2 = 1e9;
        int ans = 1e9;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                w1 = i;
            }
            if (words[i] == word2) {
                w2 = i;
            }
            cout << w1 << " and " << w2 << endl;
            ans = min(ans, abs(w2 - w1));
            cout << ans << endl;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words = {"this",    "is",       "a",   "long",    "sentence",
                            "is",      "fun",      "day", "today",   "sunny",
                            "weather", "is",       "a",   "day",     "tuesday",
                            "this",    "sentence", "run", "running", "rainy"};
    string word1 = "sentence";
    string word2 = "a";
    cout << s.shortestDistance(words, word1, word2);
}
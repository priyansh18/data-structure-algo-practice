// Find & Replace Pattern

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        ans.resize(0);
        codex.clear();
        cipher = pattern;
        for (int i = 0; i < pattern.size(); i++)
            cipher[i] = translate(cipher[i]);
        for (auto& word : words) compare(word);
        return ans;
    }

   private:
    vector<string> ans;
    unordered_map<char, char> codex;
    string cipher;
    char translate(char& c) {
        if (codex.find(c) == codex.end()) codex[c] = (char)(97 + codex.size());
        return codex[c];
    }
    void compare(string& word) {
        codex.clear();
        for (int i = 0; i < word.length(); i++)
            if (translate(word[i]) != cipher[i]) return;
        ans.push_back(word);
    }
};
int main() {
    Solution s;
    vector<string> unfiltered_words = {"abc", "deq", "mee",
                                       "aqq", "dkd", "ccc"};
    string pattern = "abb";
    vector<string> result = s.findAndReplacePattern(unfiltered_words, pattern);
    for (auto x : result) cout << x << ",";
}
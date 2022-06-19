// Word Ladder

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = wordList.size();
        int m = wordList[0].size();

        map<string, int> dict;
        for (int i = 0; i < n; i++) {
            dict[wordList[i]] = i;
        }

        if (dict.count(endWord) == 0) return 0;
        queue<string> q;
        q.push(beginWord);
        vector<int> visited(n, 0);
        vector<int> dist(n, 0);
        vector<int> parent(n, 0);

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < 26; j++) {
                    if (j == temp[i] - 'a') continue;
                    string newString = temp.substr(0, i);
                    newString += j + 'a';
                    newString += temp.substr(i + 1);
                    if (dict.count(newString) and
                        visited[dict[newString]] == 0) {
                        dist[dict[newString]] =
                            (temp == beginWord ? 1 : dist[dict[temp]] + 1);
                        visited[dict[newString]] = 1;
                        parent[dict[newString]] =
                            (temp == beginWord ? -1 : dict[temp]);
                        q.push(newString);
                    }
                }
            }
        }

        return dist[dict[endWord]] == 0 ? 0 : dist[dict[endWord]] + 1;
    }
};

int main() {
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
}
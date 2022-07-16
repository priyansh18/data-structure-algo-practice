#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    char ch;
    unordered_map<char, Node*> m;
    bool isTerminal;
    int prefixMatchCount;

    Node(char ch) {
        this->ch = ch;
        isTerminal = false;
        prefixMatchCount = 0;
    }
};

class Trie {
   public:
    Node* root;

    Trie() { root = new Node('\0'); }

    void insert(string word) {
        Node* temp = root;
        for (char ch : word) {
            if (temp->m.count(ch) == 0) {
                Node* n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
            temp->prefixMatchCount++;
        }

        temp->isTerminal = true;
    }

    int search(string str) {
        Node* temp = root;
        int ans = 0;
        for (int i = 0; i < str.length(); i++) {
            if (temp->m.count(str[i]) != 0) {
                temp = temp->m[str[i]];
                ans += temp->prefixMatchCount;
            } else {
                return 0;
            }
        }
        return ans;
    }
};

class Solution {
   public:
    vector<int> prefixMatch(vector<string> arr, int n, int k) {
        Trie t;
        vector<int> result;
        for (auto x : arr) {
            t.insert(x);
        }

        for (auto x : arr) {
            result.push_back(t.search(x));
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> arr = {"aab", "aac"};
    vector<string> arr2 = {"abc", "def"};
    int n = 2;
    int k = 3;
    vector<int> result = s.prefixMatch(arr2, n, k);
    for (auto x : result) {
        cout << x << ",";
    }
}
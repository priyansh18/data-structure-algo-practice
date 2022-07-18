#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    char data;
    unordered_map<char, Node *> m;
    bool isTerminal;
    int prefixMatchCount;

    Node(char data) {
        this->data = data;
        this->isTerminal = false;
        prefixMatchCount = 0;
    }
};

class Trie {
   public:
    Node *root;
    Trie() {
        root = new Node('\0');
        root->prefixMatchCount = 1;
    }

    void insert(string word) {
        Node *temp = root;
        for (auto x : word) {
            if (temp->m.count(x) == 0) {
                Node *n = new Node(x);
                temp->m[x] = n;
            }
            temp = temp->m[x];
            temp->prefixMatchCount++;
        }
        temp->isTerminal = true;
    }

    string prefix() {
        string output;
        if (root->m.size() < 1) {
            return output;
        }
        if (root->m.size() > 1) {
            return output;
        }

        Node *temp = ((root->m).begin())->second;
        output += temp->data;
        while (temp and temp->m.size() == 1) {
            temp = ((temp->m).begin())->second;
            output += temp->data;
        }

        return output;
    }
};

string longestCommonPrefix(vector<string> &A) {
    Trie t;
    for (auto x : A) {
        t.insert(x);
    }

    return t.prefix();
}

int main() {
    vector<string> A = {"abcdefgh", "aefghijk", "abcefgh"};
    cout << longestCommonPrefix(A) << endl;
}
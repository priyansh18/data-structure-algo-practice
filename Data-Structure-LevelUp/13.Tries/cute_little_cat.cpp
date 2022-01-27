#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class node {
   public:
    char ch;
    unordered_map<char, node*> m;
    bool isTerminal;

    node(char ch) {
        this->ch = ch;
        isTerminal = false;
    }
};

class Trie {
   public:
    node* root;

    Trie() { root = new node('\0'); }

    void insert(string word) {
        node* temp = root;

        for (char ch : word) {
            // Check if the node is already present or not
            if (temp->m.count(ch) == 0) {
                node* n = new node(ch);
                temp->m[ch] = n;
            }

            temp = temp->m[ch];
        }

        temp->isTerminal = true;
    }
};

void searchHelper(Trie t, string document, int i,
                  unordered_map<string, bool>& m) {
    node* temp = t.root;
    for (int j = i; j < document.length(); j++) {
        char ch = document[j];
        if (temp->m.count(ch) == 0) {
            return;
        }
        temp = temp->m[ch];
        if (temp->isTerminal) {
            string out = document.substr(i, j - i + 1);
            m[out] = true;
        }
    }

    return;
}

void documentSearch(string document, vector<string> words) {
    Trie t;
    for (auto x : words) {
        t.insert(x);
    }

    // Searching
    unordered_map<string, bool> m;
    for (int i = 0; i < document.length(); i++) {
        searchHelper(t, document, i, m);
    }

    for (auto x : words) {
        if (m[x]) {
            cout << x << " : True" << endl;
        } else {
            cout << x << " : False" << endl;
        }
    }
    cout << endl;
}

int main() {
    string document = "little cute cat loves to code in c++,java & python";
    vector<string> words = {"cute cat", "ttle", "quick", "big","cat"};

    documentSearch(document, words);
}
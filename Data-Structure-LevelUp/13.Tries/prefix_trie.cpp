#include <iostream>
#include <string>
#include <unordered_map>
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

    bool search(string word) {
        node* temp = root;
        for (char ch : word) {
            if (temp->m.count(ch) == 0) {
                return false;
            }
            temp = temp->m[ch];
        }

        return temp->isTerminal;
    }
};

int main() {
    Trie t;
    string words[] = {"news", "mango", "apple", "ape", "no", "not", "never"};
    for (auto word : words) {
        t.insert(word);
    }

    cout << t.search("ape") << endl;
    cout << t.search("noww") << endl;
    cout << t.search("mango") << endl;
    cout << t.search("orange") << endl;
}
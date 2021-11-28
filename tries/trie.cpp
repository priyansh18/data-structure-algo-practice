#include "trie.h"

#include <iostream>
using namespace std;

int main() {
    Trie t;
    t.insert("hello");
    t.insert("hai");
    t.insert("mango");
    t.insert("chacha");
    t.insert("pot");
    t.insert("chomu");
    t.insert("mota");

    string word;
    cin >> word;
    if (t.search(word)) {
        cout << "Present";
    } else {
        cout << "Absent";
    }
}
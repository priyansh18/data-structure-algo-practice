#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    string key;
    int value;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
    }
};

// LRU Cache Data Structure

class LRUCache {
   public:
    int maxSize;
    list<Node> l;
    unordered_map<string, list<Node>::iterator> m;

    LRUCache(int maxSize) { this->maxSize = maxSize > 1 ? maxSize : 1; }

    void insertKey(string key, int value) {
        // 2 Cases.
        // If present in cache
        if (m.count(key) != 0) {
            // Update the old value with new one
            auto it = m[key];
            it->value = value;
        } else {
            // Check if cache is full or not
            // Remove least recently  used item
            if (l.size() == maxSize) {
                Node last = l.back();
                m.erase(last.key);
                l.pop_back();
            }
            Node n(key, value);
            l.push_front(n);
            m[key] = l.begin();
        }
    }

    int getValue(string key) {
        if (m.count(key) != 0) {
            auto it = m[key];
            int value = it->value;
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return value;
        }

        return -1;
    }

    string mostRecentKey() { return l.front().key; }
};

int main() {
    LRUCache lru(3);

    lru.insertKey("mango", 10);
    lru.insertKey("apple", 20);
    lru.insertKey("guava", 30);
    cout << lru.mostRecentKey() << endl;
    lru.insertKey("mango", 40);
    cout << lru.mostRecentKey() << endl;
     lru.insertKey("banana", 20);

    if (lru.getValue("apple") == -1) {
        cout << "apple doesn't exist" << endl;
    }

    if (lru.getValue("guava") == -1) {
        cout << "guava doesn't exist" << endl;
    }
    if (lru.getValue("banana") == -1) {
        cout << "banana doesn't exist" << endl;
    }
    if (lru.getValue("mango") == -1) {
        cout << "mango doesn't exist" << endl;
    }
}
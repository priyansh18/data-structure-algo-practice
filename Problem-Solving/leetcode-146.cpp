// LRU Cache

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int key;
    int value;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
   public:
    int maxSize;
    list<Node> l;
    unordered_map<int, list<Node>::iterator> m;

    LRUCache(int capacity) { this->maxSize = capacity > 1 ? capacity : 1; }

    int get(int key) {
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

    void put(int key, int value) {
        // 2 Cases.
        // If present in cache
        if (m.count(key) != 0) {
            // Update the old value with new one
            auto it = m[key];
            it->value = value;
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
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
};

int main() {
    LRUCache lru(3);

    lru.put(435, 10);
    lru.put(123, 20);
    lru.put(987, 30);

    if (lru.get(435) == -1) {
        cout << "435 doesn't exist" << endl;
    }

    if (lru.get(983) == -1) {
        cout << "983 doesn't exist" << endl;
    }
    if (lru.get(127) == -1) {
        cout << "127 doesn't exist" << endl;
    }
}

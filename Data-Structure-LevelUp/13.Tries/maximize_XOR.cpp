#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int c;
    unordered_map<int, Node*> m;

    Node(int c) { this->c = c; }
};

class Trie {
   public:
    Node* root;

    Trie() { root = new Node(-1); }

    void insert(int num) {
        Node* temp = root;
        for (int i = 31; i >= 0; i--) {
            // Check for bit is set or not
            int bit = (num >> i) & 1;
            if (temp->m.count(bit) == 0) {
                Node* n = new Node(bit);
                temp->m[bit] = n;
            }
            temp = temp->m[bit];
        }
    }

    int getMax(int num) {
        Node* temp = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (temp->m.count(1 - bit) != 0) {
                maxNum = maxNum | (1 << i);
                temp = temp->m[1 - bit];
            } else {
                temp = temp->m[bit];
            }
        }

        return maxNum;
    }
};

int maxXOR(vector<int> nums1, vector<int> nums2) {
    Trie t;
    for (auto x : nums1) {
        t.insert(x);
    }
    int maxI = 0;
    for (auto x : nums2) {
        maxI = max(maxI, t.getMax(x));
    }

    return maxI;
}

int main() {
    vector<int> nums1 = {6, 8};
    vector<int> nums2 = {7, 8, 2};
    cout << maxXOR(nums1, nums2) << endl;
}
// Maximum XOR of two numbers in an array

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
            int bit = (num >> i) & 1;
            if (temp->m.count(bit) == 0) {
                Node* n = new Node(bit);
                temp->m[bit] = n;
            }
            temp = temp->m[bit];
        }
    }

    int maxXOR(int num) {
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

class Solution {
   public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for (auto x : nums) {
            t.insert(x);
        }
        int maxI = 0;
        for (auto x : nums) {
            maxI = max(maxI, t.maxXOR(x));
        }

        return maxI;
    }
};

int main() {
    Solution s;
    vector<int> nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    cout << s.findMaximumXOR(nums) << endl;
}
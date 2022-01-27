#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class node {
   public:
    node* left;
    node* right;

    node() : left(NULL), right(NULL) {}
};

string convertIntToBinary(int x) {
    string s = "";
    for (int j = 31; j >= 0; j--) {
        s += to_string((x >> j) & 1);
    }
    return s;
}

class Trie {
   public:
    node* root;
    Trie() { root = new node(); }

    void insert(int x) {
        node* temp = root;
        for (int j = 31; j >= 0; j--) {
            int bit = (x >> j) & 1;

            if (bit == 0) {
                if (temp->left == NULL) temp->left = new node();
                temp = temp->left;
            } else {
                if (temp->right == NULL) temp->right = new node();
                temp = temp->right;
            }
        }
    }

    int max_xor_helper(int value) {
        int current_ans = 0;
        node* temp = root;

        for (int j = 31; j >= 0; j--) {
            int bit = (value >> j) & 1;

            if (bit == 0) {
                if (temp->right != NULL) {
                    temp = temp->right;
                    current_ans += (1 << j);
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->left != NULL) {
                    temp = temp->left;
                    current_ans += (1 << j);
                } else {
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }

    int max_xor(vector<int> arr) {
        int max_xor = 0;
        for (int i = 0; i < arr.size(); i++) {
            insert(arr[i]);
            int current_xor = max_xor_helper(arr[i]);
            max_xor = max(max_xor, current_xor);
        }

        return max_xor;
    }
};

int main() {
    Trie t;
    vector<int> arr{3, 5, 2, 25, 8, 10};
    cout << t.max_xor(arr) << endl;
    // cout << biggestXOR(arr) << endl;
}
// Top View of binary tree.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

vector<int> topView(Node* root) {
    // Your code here
    if (root == NULL) return {};
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        if (m.count(temp.second) == 0) {
            m[temp.second] = temp.first->data;
        }
        if (temp.first->left) q.push({temp.first->left, temp.second - 1});
        if (temp.first->right) q.push({temp.first->right, temp.second + 1});
    }
    vector<int> result;
    for (auto x : m) {
        result.push_back(m[x.first]);
    }
    return result;
}

int main() {}
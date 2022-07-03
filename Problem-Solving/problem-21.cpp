// Diagonal View of Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

vector<int> diagonal(Node* root) {
    // your code here
    vector<int> result;
    if (root == NULL) return {};
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        while (temp) {
            if (temp->left) q.push(temp->left);
            result.push_back(temp->data);
            temp = temp->right;
        }
    }

    return result;
}

int main() {}
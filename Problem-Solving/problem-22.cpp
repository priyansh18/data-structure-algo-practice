// Boundary Traversal of Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

vector<int> boundary(Node* root) {
    // Your code here
    vector<vector<int>> result;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    vector<int> res;
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        if (temp == NULL) {
            result.push_back(res);
            res.clear();
            if (!q.empty()) q.push(NULL);
        } else {
            res.push_back(temp->data);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    for(auto )
    
}

int main() {}
// Binary Tree To DLL

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
   public:
    pair<Node*, Node*> helper(Node* root) {
        if (root == NULL) return {NULL, NULL};
        auto leftPair = helper(root->left);
        auto rightPair = helper(root->right);
        if (leftPair.first == NULL and rightPair.first == NULL) {
            root->right = NULL;
            root->left = NULL;
            return {root, root};
        }

        if (leftPair.first != NULL and rightPair.first == NULL) {
            leftPair.second->right = root;
            root->left = leftPair.second;
            root->right = NULL;
            return {leftPair.first, root};
        }

        if (leftPair.first == NULL and rightPair.first != NULL) {
            root->right = rightPair.first;
            rightPair.first->left = root;
            root->left = NULL;
            return {root, rightPair.second};
        }

        leftPair.second->right = root;
        root->left = leftPair.second;
        root->right = rightPair.first;
        rightPair.first->left = root;
        return {leftPair.first, rightPair.second};
    }

    // Function to convert binary tree to doubly linked list and return it.
    Node* bToDLL(Node* root) {
        // your code here
        return helper(root).first;
    }
};

int main() {}
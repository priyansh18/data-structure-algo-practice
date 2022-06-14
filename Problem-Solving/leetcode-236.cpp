// Lowest Common Ancestor of a binary tree.

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == p or root == q) return root;
        TreeNode* leftSearch = lowestCommonAncestor(root, p, q);
        TreeNode* rightSearch = lowestCommonAncestor(root, p, q);
        if (!leftSearch and !rightSearch)
            return NULL;
        else if (leftSearch and rightSearch)
            return root;
        return leftSearch == NULL ? rightSearch : leftSearch;
    }

    bool findNode(TreeNode* root, TreeNode* n) {
        if (root == NULL) return false;
        if (root == n) return root;
        return findNode(root->left, n) or findNode(root->right, n);
    }

    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (findNode(root->left, p)) {
            if (findNode(root->right, q))
                return lowestCommonAncestor2(root->left, p, q);
            else
                return root;
        } else if {
            if (findNode(root->right, q))
                return lowestCommonAncestor2(root->right, p, q);
        } else {
            return root;
        }
    }
};

int main() {}
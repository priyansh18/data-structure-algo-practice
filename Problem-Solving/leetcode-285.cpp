// Inorder Successor of BST

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    void toInsert(TreeNode*& root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
            return;
        }
        if (val < root->val) {
            toInsert(root->left, val);
        }
        if (val > root->val) {
            toInsert(root->right, val);
        }
    }
    TreeNode* buildTree() {
        TreeNode* root = NULL;
        int val;
        cin >> val;
        while (val != -1) {
            toInsert(root, val);
            cin >> val;
        }
        return root;
    }
};

class Solution {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL or p == NULL) return NULL;
        if (p->right) {
            TreeNode* temp = p->right;
            while (temp->left) {
                temp = temp->left;
            }
            return temp;
        }
        // If Node doesn't have a right child
        else {
            TreeNode* temp = root;
            TreeNode* successor = NULL;
            while (temp != NULL) {
                if (temp->val > p->val) {
                    successor = temp;
                    temp = temp->left;
                } else if (temp->val < p->val) {
                    temp = temp->right;
                } else {
                    break;
                }
            }
            return successor;
        }
    }
};
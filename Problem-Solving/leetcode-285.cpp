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
    void fillResult(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        fillResult(root->left, result);
        result.push_back(root->val);
        fillResult(root->right, result);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) return NULL;

        vector<int> res;
        fillResult(root, res);
        if (res.size() == 1) return NULL;
        int i = 0;
        while (i < res.size()) {
            if (res[i] == p->val) {
                i++;
                break;
            }
            i++;
        }

        if (i > res.size()) {
            return NULL;
        } else {
            TreeNode* n = new TreeNode(res[i]);
            return n;
        }
    }
};

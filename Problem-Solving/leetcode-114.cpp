// Flatten Binary Tree to linked list

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    pair<TreeNode *, TreeNode *> helper(TreeNode *root) {
        if (root == NULL) return {NULL, NULL};
        if (root->left == NULL and root->right == NULL) return {root, root};
        if (root->left != NULL and root->right == NULL) {
            auto llPair = helper(root->left);
            root->right = llPair.first;
            root->left = NULL;
            return {root, llPair.second};
        }
        if (root->left == NULL and root->right != NULL) {
            auto llPair = helper(root->right);
            root->right = llPair.first;
            root->left = NULL return {root, llPair.second};
        }
        auto llPairLeft = helper(root->left);
        auto llPairRight = helper(root->right);
        root->right = llPairLeft.first;
        llPairLeft.second = llPairRight.first;
        return {root, llPairRight.second};
    }

    void flatten(TreeNode *root) { helper(root); }
};
// Balanced Binary Tree

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
    int heightTree(TreeNode *root) {
        if (root == NULL) return 0;
        return max(heightTree(root->left) + heightTree(root->right)) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        if (abs(heightTree(root->left) - heightTree(root->right)) <= 1)
            return true;
        return isBalanced(root->left) and isBalanced(root->right);
    }
};

int main() {}
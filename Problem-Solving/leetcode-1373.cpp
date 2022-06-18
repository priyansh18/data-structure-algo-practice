// Maximum Sum BST in Binary Tree

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
    int findMax(TreeNode *root) {
        if (root == NULL) {
            return INT_MAX;
        }

        while (root->right) {
            root = root->right;
        }

        return root->val;
    }

    int findMin(TreeNode *root) {
        if (root == NULL) {
            return INT_MIN;
        }

        while (root->left) {
            root = root->left;
        }

        return root->val;
    }

    bool isBst(TreeNode *root) {
        if (root == NULL) return true;

        return isBst(root->left) and isBst(root->right) and
               root->val > findMax(root->left) and
               root->val < findMin(root->right);
    }

    int findSum(TreeNode *root) {
        if (root == NULL) return 0;
        return findSum(root->left) + findSum(root->right) + root->val;
    }

    int maxSumBST(TreeNode *root) {
        if (root == NULL) return 0;
        if (isBst(root)) {
            return findSum(root);
        }

        if (isBst(root->left) and isBst(root->right)) {
            return max(findSum(root->left), findSum(root->right));
        }

        if (isBst(root->left) and !isBst(root->right)) {
            return max(findSum(root->left), maxSumBST(root->right));
        }

        if (isBst(root->right) and !isBst(root->left)) {
            return max(findSum(root->right), maxSumBST(root->left));
        }

        return max(maxSumBST(root->left), maxSumBST(root->right));
    }
};

int main() {}
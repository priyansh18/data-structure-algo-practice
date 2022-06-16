// Binary Search Tree to Greater Sum Tree

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
    void helper(TreeNode *&root, int &sum) {
        if (root == NULL) return;
        helper(root->right, sum);
        root->val += sum;
        sum = root->val;
        helper(root->left, sum);
    }

    TreeNode *bstToGst(TreeNode *root) {
        if (root == NULL) return NULL;
        int sum = 0;
        helper(root, sum);
        return root;
    }
};

int main() {}
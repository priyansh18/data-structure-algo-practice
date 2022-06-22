//  Binary Tree Maximum Path Sum

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
    int maxSum = INT_MIN;
    int maximumPathSum(TreeNode *root) {
        if (root == NULL) return INT_MIN;

        int leftSum = maximumPathSum(root->left);
        int rightSum = maximumPathSum(root->right);

        int ans = root->val;

        if (leftSum > 0) ans += leftSum;
        if (rightSum > 0) ans += rightSum;

        maxSum = max(maxSum, ans);
        return root->val + max(0, max(leftSum, rightSum));
    }

    int maxPathSum(TreeNode*root){
      maximumPathSum(root);
      return maxSum;
    }
};

int main() {}
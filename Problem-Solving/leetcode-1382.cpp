/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<int> inorder;

    void fillInorder(TreeNode* root) {
        if (root == NULL) return;

        fillInorder(root->left);
        inorder.push_back(root->val);
        fillInorder(root->right);
    }

    TreeNode* balance(int s, int e) {
        if (s > e) return NULL;
        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = balance(s, mid - 1);
        root->right = balance(mid + 1, e);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        fillInorder(root);
        int n = inorder.size();
        return balance(0, n - 1);
    }
};
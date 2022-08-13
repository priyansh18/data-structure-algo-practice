/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool helper(TreeNode* root, int B, vector<int>& res) {
    if (!root) return false;

    res.push_back(root->val);
    if (root->val == B) return true;
    if (helper(root->left, B, res) or helper(root->right, B, res)) return true;
    res.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    if (!A) return res;
    helper(A, B, res);
    return res;
}

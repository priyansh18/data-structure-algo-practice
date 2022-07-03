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
    void fillLeaf(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        if (root->left == NULL and root->right == NULL)
            result.push_back(root->val);
        fillLeaf(root->left, result);
        fillLeaf(root->right, result);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> result1;
        vector<int> result2;
        fillLeaf(root1, result1);
        fillLeaf(root2, result2);

        for (auto x : result1) {
            cout << x << ",";
        }

        for (auto x : result2) {
            cout << x << ",";
        }

        if (result1.size() != result2.size()) return false;

        for (int i = 0; i < result1.size(); i++) {
            if (result1[i] != result2[i]) return false;
        }

        return true;
    }
};
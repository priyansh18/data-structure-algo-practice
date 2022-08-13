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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int result = 1;
        while (!q.empty()) {
            int count = q.size();
            int start = q.front().second;
            int end = q.back().second;
            result = max(result, end - start + 1);
            for (int i = 0; i < count; i++) {
                auto temp = q.front().first;
                long idx = q.front().second;
                q.pop();
                if (temp->left) q.push({temp->left, 2 * idx + 1});
                if (temp->right) q.push({temp->right, 2 * idx + 2});
            }
        }

        return result;
    }
};
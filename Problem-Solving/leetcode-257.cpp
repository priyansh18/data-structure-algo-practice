// Binary Tree Paths

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
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
    vector<vector<int>> helper(TreeNode *root) {
        vector<vector<int>> v;
        if (root == NULL) return {};
        if (root->left == NULL and root->right == NULL) {
            vector<int> a;
            a.push_back(root->val);
            v.push_back(a);
            return v;
        }

        vector<vector<int>> leftTree = helper(root->left);
        vector<vector<int>> rightTree = helper(root->right);

        for (auto x : leftTree) {
            vector<int> a;
            a.push_back(root->val);
            for (auto y : x) {
                a.push_back(y);
            }

            v.push_back(a);
        }

        for (auto x : rightTree) {
            vector<int> a;
            a.push_back(root->val);
            for (auto y : x) {
                a.push_back(y);
            }

            v.push_back(a);
        }

        return v;
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        vector<vector<int>> result = helper(root);
        vector<string> res;
        for (auto x : result) {
            string output = "";
            for (int i = 0; i < x.size(); i++) {
                if (i != x.size() - 1) {
                    output += to_string(x[i]);
                    output += "->";
                } else {
                    output += to_string(x[i]);
                }
            }
            res.push_back(output);
        }

        return res;
};
    }

Definition for a binary tree node.
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (root == NULL) return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL) {
                // Insert New Null for next level
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                TreeNode *temp2 = q.front();
                if (temp2 == NULL) res.push_back(temp->val);
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }
        return res;
    }
};

class Solution {
   public:
    void helper(TreeNode *root, int level, vector<int> &res) {
        if (root == NULL) return;
        if (level == res.size()) res.push_back(root->val);
        helper(root->right, level + 1, res);
        helper(root->left, level + 1, res);
    }
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        helper(root, 0, res);
        return res;
    }
};
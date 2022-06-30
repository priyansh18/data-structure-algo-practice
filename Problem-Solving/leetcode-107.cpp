// Reverse Level order Traversal

//  Definition for a binary tree node.
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> res;
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (temp == NULL) {
                result.push_back(res);
                res.clear();
                if (!q.empty()) q.push(NULL);
            } else {
                res.push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
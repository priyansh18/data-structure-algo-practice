// Sum Root to leaf numbers

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
    vector<pair<int, int>> helper(TreeNode *root) {
        if (root == NULL) {
            return {};
        }
        if (root->left == NULL and root->right == NULL) {
            vector<pair<int, int>> v;
            v.push_back({root->val, 1});
            return;
        }

        vector<pair<int, int>> leftVal = helper(root->left);
        vector<pair<int, int>> rightVal = helper(root->right);

        vector<pair<int, int>> v;

        for (auto x : leftVal) {
            v.push_back(
                {(root->val) * pow(10, x.second) + x.first, x.second + 1});
        }

        for (auto x : rightVal) {
            v.push_back(
                {(root->val) * pow(10, x.second) + x.first, x.second + 1});
        }

        return v;
    }

    int sumNumbers(TreeNode *root) {
        vector<pair<int, int>> v = helper(root);
        int ans = 0;
        for (auto x : v) {
            ans += x.first;
        }
        return ans;
    }
};
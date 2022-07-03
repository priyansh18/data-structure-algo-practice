// Find Duplicates Subtrees

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
    string helper(TreeNode *root, unordered_map<string, int> &m) {
        if (root == NULL) return "$";
        string s = "";
        if (!root->right and !root->left) {
            s += to_string(root->val);
            return s;
        }
        s += to_string(root->data);
        s += helper(root->left);
        s += helper(root->right);
        m[s]++;
        return s;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        vector<TreeNode *> result;
        unordered_map<string, int> m;
        helper(root, m);
        for (auto x : m) {
            cout << x.first << " and " << x.second << endl;
        }

        return result;
    }
};

int main() {}
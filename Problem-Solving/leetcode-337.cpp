// House Robber III

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

    map<TreeNode* , int> mp;
    int rob(TreeNode *root) {
        if (!root) return 0;
        if(mp.count(root))  return mp[root];
        int opt1 = root->val;
        opt1 += root->left  ? rob(root->left->left) : 0;
        opt1 += root->left  ? rob(root->left->right) : 0;
        opt1 += root->right  ? rob(root->right->left) : 0;
        opt1 += root->right  ? rob(root->right->right) : 0;
        int opt2 = rob(root->left) + rob(root->right);

        return mp[root] = max(opt1, opt2);
    }
};

int main() {}
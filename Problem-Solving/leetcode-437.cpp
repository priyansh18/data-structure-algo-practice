// Path Sum II

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
    vector<vector<int>> helper(TreeNode *root, int targetSum) {
        if(root == NULL) return {};
        
        if (targetSum == root->val and root->left == NULL and  root->right == NULL) {
          vector<vector<int>> ans;
          ans.push_back({root->val});
        }

        if (root->left == NULL and  root->right == NULL and targetSum != root->val) {
          return {};
        }

        vector<vector<int>> fromLeftpaths = helper(root->left, targetSum - root->val);
        vector<vector<int>> fromRightpaths = helper(root->right, targetSum - root->val);
        
        vector<vector<int>> ans;
        for (auto x : fromLeftpaths) {
            vector<int> tmp;
            tmp.push_back(root->val);
            for (auto y : x) {
                tmp.push_back(y);
            }
            ans.push_back(tmp);
        }

        for (auto x : fromRightpaths) {
            vector<int> tmp;
            tmp.push_back(root->val);
            for (auto y : x) {
                tmp.push_back(y);
            }
            ans.push_back(tmp);
        }

        return ans;
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> result;
        vector<int> res;
        helper(root, targetSum, res);
        for (auto x : res) {
            cout << x << ",";
        }
        return result;
    }
};

int main() {}
// Find largest in each tree row.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class Solution {
   public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int maxVal = INT_MIN;
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (temp == NULL) {
                result.push_back(maxVal);
                maxVal = INT_MIN;
                if (!q.empty()) q.push(NULL);
            } else {
                maxVal = max(maxVal, temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        return result;
    }
};

int main(){
  
}
// Print nodes at distance k

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void fillParentNode(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        if (temp->left) {
            parent[temp->left] = temp;
            q.push(temp->left);
        }

        if (temp->right) {
            parent[temp->right] = temp;
            q.push(temp->right);
        }
    }
}

class Solution {
   public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        fillParentNode(root, parent);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        while (!q.empty()) {
            int size = q.size();
            if (k == 0) break;
            k--;
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                if (temp->left and !visited[temp->left]) {
                    visited[temp->left] = true;
                    q.push(temp->left);
                }
                if (temp->right and !visited[temp->right]) {
                    visited[temp->right] = true;
                    q.push(temp->right);
                }
                if (parent[temp] and !visited[parent[temp]]) {
                    visited[parent[temp]] = true;
                    q.push(parent[temp]);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
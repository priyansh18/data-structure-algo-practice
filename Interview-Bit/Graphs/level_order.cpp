
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> Solution::levelOrder(TreeNode *A) {
    vector<vector<int>> result;
    if (A == NULL) return {};
    queue<TreeNode *> q;
    q.push(A);
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

    return result;
}

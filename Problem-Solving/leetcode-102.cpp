// Level Order Traversal

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        data = d;
        left = right = NULL;
    }
};

TreeNode* buildTree() {
    int d;
    cin >> d;
    TreeNode* root = new TreeNode(d);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* n = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1) {
            n->left = new TreeNode(c1);
            q.push(n->left);
        }

        if (c2 != -1) {
            n->right = new TreeNode(c2);
            q.push(n->right);
        }
    }

    return root;
}

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> r;
        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();

            if (n == NULL) {
                res.push_back(r);
                r.clear();
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                r.push_back(n->data);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    TreeNode* root = buildTree();
    vector<vector<int>> result = s.levelOrder(root);
    for (auto x : result) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}
// Vertical Order Traversal of binary tree.

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        data = d;
        left = right = NULL;
    }
};

TreeNode* buildLevelOrderTree() {
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

void printLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        if (temp == NULL) {
            cout << endl;
            q.pop();
            // Insert New Null for next level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            q.pop();
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    return;
}

class Solution {
   public:
    void treeTraversal(TreeNode* root, int d, map<int, vector<int>>& m) {
        if (root == NULL) {
            return;
        }
        m[d].push_back(root->data);
        treeTraversal(root->left, d - 1, m);
        treeTraversal(root->right, d + 1, m);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<int>> m;
        int d = 0;
        treeTraversal(root, d, m);

        for (auto x : m) {
            vector<int> r;
            for (auto c : x.second) {
                r.push_back(c);
            }
            res.push_back(r);
        }

        return res;
    }
};

int main() {
    Solution s;
    TreeNode* root1 = buildLevelOrderTree();
    printLevelOrder(root1);
    cout << endl;
    vector<vector<int>> res = s.verticalTraversal(root1);

    for (auto x : res) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout<<endl;
    }
}
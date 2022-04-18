// All Elements in two binary search trees.

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
    void insertInVector(TreeNode* root, vector<int>& res) {
        if (root == NULL) {
            return;
        }

        insertInVector(root->left,res);
        res.push_back(root->data);
        insertInVector(root->right,res);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        insertInVector(root1, res);
        insertInVector(root2, res);
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    TreeNode* root1 = buildLevelOrderTree();
    printLevelOrder(root1);
    cout << endl;
    TreeNode* root2 = buildLevelOrderTree();
    printLevelOrder(root2);
    cout << endl;
    vector<int> result = s.getAllElements(root1,root2);
    for (auto x : result) {
        cout << x << ",";
    }
}
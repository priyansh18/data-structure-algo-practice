// Boundary of binary tree.

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
    void LeftTree(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        if (root->left) {
            result.push_back(root->data);
            LeftTree(root->left, result);
        } else if (root->right) {
            result.push_back(root->data);
            LeftTree(root->right, result);
        }
    }
    void leaf(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        leaf(root->left, result);
        if (root->left == NULL and root->right == NULL) {
            result.push_back(root->data);
        }
        leaf(root->right, result);
    }
    void rightTree(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        if (root->right) {
            rightTree(root->right, result);
            result.push_back(root->data);
        } else if (root->left) {
            rightTree(root->left, result);
            result.push_back(root->data);
        }
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        // write your code here
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        // Pushing root inside the vector
        result.push_back(root->data);
        LeftTree(root->left, result);
        leaf(root, result);
        rightTree(root->right, result);

        return result;
    }
};

int main() {
    Solution s;
    TreeNode* root1 = buildLevelOrderTree();
    printLevelOrder(root1);
    cout << endl;
    vector<int> res = s.boundaryOfBinaryTree(root1);
    for (auto x : res) {
        cout << x << ",";
    }
}
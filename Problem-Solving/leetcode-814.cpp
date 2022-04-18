// Binary Tree Pruning

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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* leftAns = pruneTree(root->left);
        TreeNode* rightAns = pruneTree(root->right);

        if (leftAns == NULL and rightAns == NULL) {
            if (root->data != 1) {
                root->left = NULL;
                root->right = NULL;
                return NULL;
            } else {
                root->left = NULL;
                root->right = NULL;
                return root;
            }
        }
        if (leftAns == NULL) {
            root->left = NULL;
            root->right = rightAns;
            return root;
        }
        if (rightAns == NULL) {
            root->right = NULL;
            root->left = leftAns;
            return root;
        }

        return root;
    }
};

int main() {
    Solution s;
    TreeNode* root1 = buildLevelOrderTree();
    printLevelOrder(root1);
    cout << endl;
    TreeNode* root = s.pruneTree(root1);
    printLevelOrder(root);
}
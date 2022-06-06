// Binary Tree Colouring problem.

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) {
        this->key = key;
        left = right = NULL;
    }

    TreeNode* buildTree() {
        queue<TreeNode*> q;
        int data;
        cin >> data;
        TreeNode* root = new TreeNode(data);
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            int d1, d2;
            cin >> d1 >> d2;

            if (d1 != -1) {
                temp->left = new TreeNode(d1);
                q.push(temp->left);
            }

            if (d2 != -1) {
                temp->right = new TreeNode(d2);
                q.push(temp->right);
            }
        }

        return root;
    }

    void printLevelOrder(TreeNode* root) {
        if (root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL) {
                cout << endl;
                if (!q.empty()) q.push(NULL);
            } else {
                cout << temp->key << " ";
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
    }
};

class Solution {
   public:
    TreeNode* findNode(TreeNode* root, int x) {
        if (root == NULL) return NULL;
        if (root->key == x) return root;
        TreeNode* Ltree = findNode(root->left, x);
        TreeNode* Rtree = findNode(root->right, x);

        if (Ltree != NULL) return Ltree;
        if (Rtree != NULL) return Rtree;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int lCount = countNodes(root->left);
        int rCount = countNodes(root->right);

        return lCount + rCount + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* temp = findNode(root, x);
        int leftNode = countNodes(temp->left);
        int rightNode = countNodes(temp->right);
        int remainingNode = n - (leftNode + rightNode) - 1;
        cout << remainingNode << endl;

        if (leftNode > rightNode + remainingNode) return true;
        if (rightNode > leftNode + remainingNode) return true;
        if (remainingNode > rightNode + leftNode) return true;
        return false;
    }
};

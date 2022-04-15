// Diameter of binary tree.

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
    int heightBinaryTree(TreeNode* root) {
        // Base Case
        if (root == NULL) {
            return 0;
        }

        // Logic
        int h1 = heightBinaryTree(root->left);
        int h2 = heightBinaryTree(root->right);

        return max(h1, h2) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int d3 = heightBinaryTree(root->left) + heightBinaryTree(root->right);
        int d1 = diameterOfBinaryTree(root->left);
        int d2 = diameterOfBinaryTree(root->right);

        return max(d1, max(d2, d3));
    }
};

int main() {
    Solution s;
    TreeNode* root1 = buildLevelOrderTree();
    printLevelOrder(root1);
    cout << endl;
    cout<<s.diameterOfBinaryTree(root1)<<endl;
    cout<<s.heightBinaryTree(root1)<<endl;
}
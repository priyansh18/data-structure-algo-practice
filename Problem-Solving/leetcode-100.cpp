//  Same Tree.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL and q == NULL) {
            return true;
        }
        if (p == NULL) return false;
        if (q == NULL) return false;

        if (p->data != q->data) {
            return false;
        }

        bool leftData = isSameTree(p->left, q->left);
        bool rightData = isSameTree(p->right, q->right);

        return leftData and rightData;
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
    cout << s.isSameTree(root1, root2) << endl;
}
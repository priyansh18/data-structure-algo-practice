// Validate Binary Search Tree.

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
    long long findMax(TreeNode* root) {
        while (root and root->right) {
            root = root->right;
        }

        if (root == NULL) {
            return LONG_MIN;
        }

        return root->data;
    }

    long long findMin(TreeNode* root) {
        while (root and root->left) {
            root = root->left;
        }

        if (root == NULL) {
            return LONG_MAX;
        }

        return root->data;
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        bool isLeftValidBST = isValidBST(root->left);
        bool isRightValidBST = isValidBST(root->right);
        long long maxValue = findMax(root->left);
        long long minValue = findMin(root->right);
        return isLeftValidBST and isRightValidBST and root->data > maxValue and
               root->data < minValue;
    }
};

class Solution {
   public:
    bool helper(TreeNode* root, long long minV, long long maxV) {
        if (root == NULL) return true;
        if (root->val <= minV or root->val >= maxV) return false;
        return helper(root->left, minV, root->val) &&
               helper(root->right, root->val, maxV);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};

int main() {
    Solution s;
    TreeNode* root1 = buildLevelOrderTree();
    printLevelOrder(root1);
    cout << endl;
    cout << s.isValidBST(root1) << endl;
}
// Check Children Sum Parent Property.


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
    int isSumProperty(TreeNode* root) {
        // Base Case
        if (root == NULL or (root->left == NULL and root->right == NULL)) {
            return 1;
        }
        int left_sum = 0;
        int right_sum = 0;

        if (root->left != NULL) {
            left_sum = root->left->data;
        }

        if (root->right != NULL) {
            right_sum = root->right->data;
        }

        if ((root->data == left_sum + right_sum) and
            isSumProperty(root->left) and isSumProperty(root->right)) {
            return 1;
        }

        return 0;
    }
};

int main() {
    Solution s;
    TreeNode* root1 = buildLevelOrderTree();
    printLevelOrder(root1);
    cout << endl;
    cout << s.isSumProperty(root1) << endl;
}
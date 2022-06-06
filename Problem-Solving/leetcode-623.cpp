// Add one row to tree

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }

    TreeNode* buildTreefromLevelOrder() {
        queue<TreeNode*> q;

        int data;
        cin >> data;

        TreeNode* root = new TreeNode(data);

        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            int c1, c2;
            cin >> c1 >> c2;

            if (c1 != -1) {
                temp->left = new TreeNode(c1);
                q.push(temp->left);
            }
            if (c2 != -1) {
                temp->right = new TreeNode(c2);
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
                cout << temp->val << " ";
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
    }
};

// It Takes Linear Time if given depth equals to depth of tree in worst case we might need to traverse every single node which is O(n). 

class Solution {
   public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }

        queue<TreeNode*> q;
        int l = 2;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front == NULL) {
                l++;
                if (!q.empty()) q.push(NULL);
            } else {
                if (l == depth) {
                    TreeNode* x = front->left;
                    TreeNode* y = front->right;
                    TreeNode* n1 = new TreeNode(val);
                    TreeNode* n2 = new TreeNode(val);
                    front->left = n1;
                    front->right = n2;
                    n1->left = x;
                    n2->right = y;
                } else {
                    if (front->left) q.push(front->left);
                    if (front->right) q.push(front->right);
                }
            }
        }

        return root;
    }
};

int main() {
    Solution s;
    TreeNode* t;
    TreeNode* root = t->buildTreefromLevelOrder();
    t->printLevelOrder(root);
    cout << endl;
    TreeNode* newRoot = s.addOneRow(root, 1, 2);
    t->printLevelOrder(newRoot);
}
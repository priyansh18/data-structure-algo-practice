// Construct Binary Tree from Postorder and Inorder Traversal

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

class Solution {
   public:
    TreeNode *build(vector<int> inorder, vector<int> postorder, int ps, int pe,
                    int is, int ie) {
        // Postorder contains last node as root
        if (is > ie) return NULL;
        TreeNode *n = new TreeNode(postorder[pe]);
        int i = is;
        for (; i <= ie; i++) {
            if (inorder[i] == postorder[pe]) {
                break;
            }
        }

        n->left = build(inorder, postorder, ps, ps + i - is - 1, is, i - 1);
        n->right = build(inorder, postorder, ps + i - is, pe - 1, i + 1, ie);
        return n;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = postorder.size();
        int m = inorder.size();
        return build(inorder, postorder, 0, n - 1, 0, m - 1);
    }
};

int main() {
    Solution s;
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = s.buildTree(inorder, postorder);

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
            continue;
        }
        cout << temp->val << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}
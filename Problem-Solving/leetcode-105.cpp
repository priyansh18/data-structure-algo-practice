// Construct Binary Tree from Preorder and Inorder Traversal
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
};

class Solution {
   public:
    TreeNode* build(vector<int> preorder, vector<int> inorder, int ps, int pe,
                    int is, int ie) {
        if (is > ie) {
            return NULL;
        }
        TreeNode* n = new TreeNode(preorder[ps]);
        int j = is;
        for (; j <= ie; j++) {
            if (preorder[ps] == inorder[j]) {
                break;
            }
        }
        n->left = build(preorder, inorder, ps + 1, ps + j - is, is, j - 1);
        n->right = build(preorder, inorder, ps + j - is + 1, pe, j + 1, ie);
        return n;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = inorder.size();
        return build(preorder, inorder, 0, m - 1, 0, n - 1);
    }
};

int main() {
    Solution s;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = s.buildTree(preorder, inorder);

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode* temp = q.front();
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

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    if (A == NULL) return {};
    vector<int> preorder;
    stack<TreeNode*> st;
    st.push(A);
    while (!st.empty()) {
        auto temp = st.top();
        st.pop();
        preorder.push_back(temp->val);
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }

    return preorder;
}

int main() {}
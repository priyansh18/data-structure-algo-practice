/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> postorder;
    if (A == NULL) return postorder;
    stack<TreeNode*> st1, st2;
    st1.push(A);
    while (!st1.empty()) {
        A = st1.top();
        st1.pop();
        st2.push(A);
        if (A->left) st1.push(A->left);
        if (A->right) st1.push(A->right);
    }
    while (!st2.empty()) {
        postorder.push_back(st2.top()->val);
        st2.pop();
    }

    return postorder;
}

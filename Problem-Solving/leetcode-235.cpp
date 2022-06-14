// Lowest Common Ancestor of a binary search tree.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == p or root == q) return root;
        if(root->val< p->val and root->val < q->val){
           return lowestCommonAncestor(root->right, p, q);
        }else if((root->val<p->val and root->val>q->val) or (root->val>p->val and root->val<q->val)){
            return root;
        }else{
            return lowestCommonAncestor(root->left, p, q);
        }
        
    }
};
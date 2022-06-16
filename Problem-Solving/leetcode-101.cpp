// Symmetric Tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool mirror(TreeNode *left_part, TreeNode *right_part) {
        if (left_part == NULL and right_part == NULL) return NULL;
        if (left_part->val != right_part->val) return false;
        if (mirror(left_part->left, right_part->right) and
            mirror(left_part->right, right_part->left))
            return true;
        return false;
    }

    bool isSymmetric(TreeNode *root) { return mirror(root, root); }
};
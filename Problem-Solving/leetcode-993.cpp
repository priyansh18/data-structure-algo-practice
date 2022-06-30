// Cousins in binary tree.

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
    int findLevel(TreeNode *root, int v) {
        queue<TreeNode *> q;
        int level = 0;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (temp == NULL) {
                level++;
                if (!q.empty()) q.push(NULL);
            } else {
                if (temp->val == v) {
                    return level;
                }
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        return level;
    }

    int findParent(TreeNode *root, int v) {
        if (root == NULL) return -1;
        if (root->left == NULL and root->right == NULL) return -1;
        if (root->left == NULL and root->right != NULL) {
            if (root->right->val == v) {
                return root->val;
            } else {
                return findParent(root->right, v);
            }
        }
        if (root->left != NULL and root->right == NULL) {
            if (root->left->val == v) {
                return root->val;
            } else {
                return findParent(root->left, v);
            }
        }
        if (root->left->val == v or root->right->val == v) {
            return root->val;
        }
        int right = findParent(root->right, v);
        int left = findParent(root->left, v);
        if (right != -1) return right;
        if (left != -1) return left;

        return -1;
    }

    bool isCousins(TreeNode *root, int x, int y) {
        if (root->val == x or root->val == y) return false;
        int findLevelX = findLevel(root, x);
        int findLevelY = findLevel(root, y);

        if (findLevelX != findLevelY) {
            return false;
        }

        int findParentX = findParent(root, x);
        int findParentY = findParent(root, y);

        cout << findParentX << endl;
        cout << findParentY << endl;

        if (findParentX == findParentY) {
            return false;
        }
        return true;
    }
};
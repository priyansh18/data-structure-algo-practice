#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> solve(TreeNode *A, int B) {
    vector<int> result;
    if (A == NULL) return result;
    if (A->val == B) return result;
    queue<TreeNode *> q;
    q.push(A);
    q.push(NULL);
    bool nextLevelFilled = false;
    bool canFill = false;
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        if (canFill) {
            result.push_back(temp->val);
        } else {
            if (temp == NULL) {
                if (nextLevelFilled) {
                    canFill = true;
                }
                if (!q.empty()) q.push(NULL);
            } else {
                if ((temp->left and temp->left->val == B) or
                    (temp->right and temp->right->val == B)) {
                    nextLevelFilled = true;
                } else {
                    if (temp->left) q.push(temp->left);
                    if (temp->right) q.push(temp->right);
                }
            }
        }
    }

    return result;
}

int main() {}
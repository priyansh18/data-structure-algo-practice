#include <bits/stdc++.h>
using namespace std;

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

vector<int> preorder;
vector<int> postorder;
vector<int> inorder;

void Traversals(TreeNode* root) {
    if (root == NULL) return;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    while (!st.empty()) {
        auto temp = st.top();
        st.pop();
        if (temp.second == 1) {
            preorder.push_back(temp.first->data);
            temp.second++;
            st.push(temp);
            if (temp.first->left) st.push({temp.first->left, 1});
        } else if (temp.second == 2) {
            inorder.push_back(temp.first->data);
            temp.second++;
            st.push(temp);
            if (temp.first->right) st.push({temp.first->right, 1});
        } else {
            postorder.push_back(temp.first->data);
        }
    }
}

class Solution {
   public:
};

int main() {
    Solution s;
    TreeNode* root1 = buildLevelOrderTree();
    Traversals(root1);
    for (auto x : preorder) cout << x << ",";
    cout << endl;
    for (auto x : inorder) cout << x << ",";
    cout << endl;
    for (auto x : postorder) cout << x << ",";
    cout << endl;
}
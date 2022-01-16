#include <iostream>
#include <queue>
using namespace std;

class node {
   public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree() {
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    node* n = new node(data);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

int buildDescendantSum(node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL and root->right == NULL) {
        return root->data;
    }

    int temp = root->data;
    int leftSum = buildDescendantSum(root->left);
    int rightSum = buildDescendantSum(root->right);

    root->data = leftSum + rightSum;

    return leftSum + rightSum + temp;
}

void levelOrderPrint(node* root) {
    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* val = q.front();
        q.pop();
        if (val == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
            continue;
        }
        cout << val->data << " ";
        if (val->left) q.push(val->left);
        if (val->right) q.push(val->right);
    }
}

int main() {
    node* t = buildTree();
    levelOrderPrint(t);
    buildDescendantSum(t);
    levelOrderPrint(t);
}
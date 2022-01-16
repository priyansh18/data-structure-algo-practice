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

int heightBinaryTree(node* root) {
    // Base Case
    if (root == NULL) {
        return 0;
    }

    // Logic
    int h1 = heightBinaryTree(root->left);
    int h2 = heightBinaryTree(root->right);

    return max(h1, h2) + 1;
}

bool isHeightBalanced(node* root) {

    if (root == NULL) return true;
    bool isLeftBal = isHeightBalanced(root->left);
    bool isRightBal = isHeightBalanced(root->right);
    int h1 = heightBinaryTree(root->left);
    int h2 = heightBinaryTree(root->right);

    return abs(h2 - h1) <= 1 and isLeftBal and isRightBal;
}

int main() {
    node* t = buildTree();
    cout << heightBinaryTree(t) << endl;
    cout << isHeightBalanced(t) << endl;
}
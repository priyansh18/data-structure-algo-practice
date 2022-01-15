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

int diameterBinaryTree(node* root) {
    if (root == NULL) {
        return 0;
    }
    int d3 = heightBinaryTree(root->left) + heightBinaryTree(root->right);
    int d1 = diameterBinaryTree(root->left);
    int d2 = diameterBinaryTree(root->right);

    return max(d1, max(d2, d3));
}

int main() {
    node* t = buildTree();
    cout << heightBinaryTree(t) << endl;
    cout << diameterBinaryTree(t) << endl;
}
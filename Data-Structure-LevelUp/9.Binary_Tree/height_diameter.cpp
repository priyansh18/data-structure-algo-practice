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

class HDpair {
   public:
    int height;
    int diameter;

};

HDpair diameterBinaryTreeOptimized(node* root) {
    HDpair p;
    if (root == NULL) {
        p.height = p.diameter = 0;
        return p;
    }

    HDpair left = diameterBinaryTreeOptimized(root->left);
    HDpair right = diameterBinaryTreeOptimized(root->right);

    p.height = max(left.height, right.height) + 1;

    int d1 = left.height + right.height;
    int d2 = left.diameter;
    int d3 = right.diameter;

    p.diameter = max(d1, max(d2, d3));

    return p;
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
    cout << diameterBinaryTreeOptimized(t).diameter << endl;
}
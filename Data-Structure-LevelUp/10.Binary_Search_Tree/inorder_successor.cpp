#include <iostream>
#include <queue>
using namespace std;

class node {
   public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void toInsert(node*& root, int data) {
    if (root == NULL) {
        root = new node(data);
        return;
    }
    if (data < root->data) {
        toInsert(root->left, data);
    }
    if (data > root->data) {
        toInsert(root->right, data);
    }
}

node* buildTree() {
    node* root = NULL;
    int data;
    cin >> data;
    while (data != -1) {
        toInsert(root, data);
        cin >> data;
    }
    return root;
}

void printTree(node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout << root->data << ",";
    printTree(root->right);
}

node* getTargetNode(node* root, node* target, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        target = root;
    } else if (root->data > key) {
        target = getTargetNode(root->left, key);
    } else {
        target = getTargetNode(root->right, key);
    }

    return target;
}

node* inorderSuccessor(node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        node* target = NULL;
        target = root;
        if (target->right != NULL) {
            node* newVal = target->right;
            while (newVal->left != NULL) {
                newVal = newVal->left;
            }

            return newVal;
        }
        else {
          
        }

    } else if (root->data > key) {
        return inorderSuccessor(root->left, key);
    } else {
        return inorderSuccessor(root->right, key);
    }
}

int main() {
    node* t = buildTree();
    printTree(t);
    cout << endl;
}
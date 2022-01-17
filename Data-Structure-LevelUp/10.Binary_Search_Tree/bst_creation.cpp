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

bool search(node* root, int target) {
    if (root == NULL) {
        return false;
    }
    if (root->data == target) {
        return true;
    } else if (root->data > target) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

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

node* heightBalancedBst(){

}

void printTree(node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout << root->data << ",";
    printTree(root->right);
}

int main() {
    node* t = buildTree();
    printTree(t);
    cout << endl;
    if (search(t, 4)) {
        cout << "Element Found";
    } else {
        cout << "Element not found";
    }
    cout << endl;
    if (search(t, 41)) {
        cout << "Element Found";
    } else {
        cout << "Element not found";
    }
    cout << endl;

    

}
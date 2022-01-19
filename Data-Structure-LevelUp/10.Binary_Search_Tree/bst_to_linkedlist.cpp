#include <iostream>
#include <queue>
#include <vector>
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

// BST to sorted linked list
class LL {
   public:
    node* head;
    node* tail;
};

LL bstToLinkedList(node* root) {
    LL l;
    if (root == NULL or (root->left == NULL and root->right == NULL)) {
        l.head = l.tail = root;
        return l;
    }
    if (root->left != NULL and root->right == NULL) {
        LL leftLL = bstToLinkedList(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;

        return l;
    }
    if (root->left == NULL and root->right != NULL) {
        LL rightLL = bstToLinkedList(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    if (root->left != NULL and root->right != NULL) {
        LL leftLL = bstToLinkedList(root->left);
        LL rightLL = bstToLinkedList(root->right);

        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;

        return l;
    }

    return l;
}

int main() {
    node* t = buildTree();
    printTree(t);
    cout<<endl;
    LL l = bstToLinkedList(t);
    node* temp = l.head;
    while (temp != NULL) {
        cout << temp->data << "-->";
        temp = temp->right;
    }
}

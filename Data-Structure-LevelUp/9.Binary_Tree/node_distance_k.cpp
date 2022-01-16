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


void printKLevel(node* root, int k) {
    if (root == NULL) {
        return;
    }

    if (k == 0) {
        cout << root->data << " ";
    }

    printKLevel(root->left, k - 1);
    printKLevel(root->right, k - 1);
}

int printNodeAtDistanceK(node* root, node* target, int k) {
    if (root == NULL) {
        return -1;
    }

    if (root == target) {
        printKLevel(target, k);
        return 0;
    }

    int distanceLeft = printNodeAtDistanceK(root->left, target, k);
    if (distanceLeft != -1) {
        // Print the current node
        if (distanceLeft + 1 == k) {
            cout << root->data << " ";
        } else {
            printKLevel(root->right, k - 2 - distanceLeft);
        }

        return 1 + distanceLeft;
    }
    int distanceRight = printNodeAtDistanceK(root->right, target, k);
    if (distanceRight != -1) {
        // Print the current node
        if (distanceRight + 1 == k) {
            cout << root->data << " ";
        } else {
            printKLevel(root->left, k - 2 - distanceRight);
        }

        return 1 + distanceRight;
    }

    return -1;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->left->right->right->left = new node(9);
    root->left->right->right->right = new node(10);

    node* target = root->left->right;

    int k = 2;

    printNodeAtDistanceK(root,target,k);
    cout<<endl;
}
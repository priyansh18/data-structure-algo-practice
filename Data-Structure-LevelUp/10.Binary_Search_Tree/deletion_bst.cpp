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

node* deletionBst(node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == key) {
        // If root has no child
        if (root->left == NULL and root->right == NULL) {
            root = NULL;
            return root;
        }

        // If the root has left child
        if (root->left != NULL and root->right == NULL) {
            node* temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        // If the root has right child
        if (root->left == NULL and root->right != NULL) {
            node* temp = root;
            root = root->right;
            delete temp;
            return root;
        }

        // If root has both left and right child
        if (root->left != NULL and root->right != NULL) {
            node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            swap(temp->data, root->data);
            temp->left = deletionBst(temp, key);
            return root;
        }

        // if (root->left != NULL and root->right != NULL) {
        //     node* temp = root->right;
        //     while(temp->left!=NULL){
        //       temp =t
        //     }

        //     while (temp->left->left != NULL) {
        //         prev = temp->left;
        //         temp = temp->left;
        //     }
        //     swap(temp->data, root->data);
        //     prev->left = deletionBst(temp, key);
        // }
    } else if (root->data > key) {
        root->left = deletionBst(root->left, key);
    } else {
        root->right = deletionBst(root->right, key);
    }
}

node* deleteBST(node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data > key) {
        root->left = deleteBST(root->left, key);
        return root;
    }

    if (root->data < key) {
        root->right = deleteBST(root->right, key);
        return root;
    }
    
    // If root has no child
    if (root->left == NULL and root->right == NULL) {
        delete root;
        return NULL;
    }

    // If the root has left child
    if (root->left != NULL and root->right == NULL) {
        node* temp = root->left;
        delete root;
        return temp;
    }
    
    // If the root has right child
    if (root->left == NULL and root->right != NULL) {
        node* temp = root->right;
        delete root;
        return temp;
    }

    // If root has both left and right child
    if (root->left != NULL and root->right != NULL) {
      node* temp = root->right;
      while (temp->left != NULL) {
          temp = temp->left;
      }
      swap(temp->data, root->data);
      root->right = deleteBST(root->right, temp->data);
      return root;
    }
}

int main() {
    node* t = buildTree();
    printTree(t);
    cout << endl;
    // deletionBst(t, 8);
    node* root = deleteBST(t, 8);
    printTree(root);
    cout << endl;
}
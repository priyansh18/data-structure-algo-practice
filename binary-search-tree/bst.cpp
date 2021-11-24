#include <iostream>
using namespace std;

class Node {
   public:
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) {
        Node* n = new Node(key);
        return n;
    } else {
        if (root->key < key) {
            root->right = insert(root->right, key);
        } else {
            root->left = insert(root->left, key);
        }
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* remove(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    } else if (key < root->key) {
        root->left = remove(root->left, key);
    } else if (key > root->key) {
        root->right = remove(root->right, key);
    } else {
        //  When Current Node matches with the key

        // Case:1 No Child Node.
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return root;
        }

        // Case:2 One Child Node
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }

        // Case:3 Two Child Node
        else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }

    return root;
}

bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }

    if (root->key == key) {
        return true;
    } else if (root->key < key) {
        return search(root->right, key);
    } else {
        return search(root->left, key);
    }

    return false;
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->key << " ";
    printInOrder(root->right);
}

void printInRange(Node* root, int k1, int k2) {
    if (root == NULL) {
        return;
    }
    if (root->key >= k1 and root->key <= k2) {
        // call on both side
        printInRange(root->left, k1, k2);
        cout << root->key << " ";
        printInRange(root->right, k1, k2);
    } else if (root->key > k2) {
        printInRange(root->left, k1, k2);
    } else {
        printInRange(root->right, k1, k2);
    }
}

int main() {
    Node* root = NULL;
    int arr[] = {8, 3, 1, 10, 5, 7, 19, 13};

    for (int x : arr) {
        root = insert(root, x);
    }
    cout << "Inorder Print : ";
    printInOrder(root);
    cout << endl;
    int k1, k2;
    cin >> k1 >> k2;
    cout << "Print In Range" << k1 << " and " << k2 << " : ";
    printInRange(root, k1, k2);
    cout << endl;

    cout << search(root, 8) << endl;
    cout << search(root, 1) << endl;
    cout << search(root, 222) << endl;
    cout << search(root, 123) << endl;
    cout << search(root, 5) << endl;

    remove(root, 0);
    printInOrder(root);
    cout << endl;
    remove(root, 3);
    printInOrder(root);
    cout << endl;
    remove(root, 8);
    printInOrder(root);
    cout << endl;
    remove(root, 14);
    printInOrder(root);
}
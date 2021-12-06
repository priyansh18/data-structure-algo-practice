#include <iostream>
#include <queue>
using namespace std;

// Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// Preorder Output : 1 2 4 5 7 3 6
// Inorder Output : 4 2 7 5 1 3 6
// PostOrder Output : 4 7 5 2 6 3 1

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

Node* buildTree() {
    int d;
    cin >> d;

    if (d == -1) {
        return NULL;
    }

    Node* n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printPreOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPostOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int heightBinaryTree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int heightLeft = heightBinaryTree(root->left);
    int heightRight = heightBinaryTree(root->right);

    return 1 + max(heightLeft, heightRight);
}

// Time Complexity is O(n^2)
int diameter(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int diameter1 =
        heightBinaryTree(root->left) + heightBinaryTree(root->right);
    int diameter2 = diameter(root->left);
    int diameter3 = diameter(root->right);

    return max(diameter1, max(diameter2, diameter3));
}

class HDPair {
   public:
    int height;
    int diameter;
};

HDPair diameterOptimized(Node* root) {
    HDPair p;
    if (root == NULL) {
        p.height = p.diameter = 0;
        return p;
    }

    HDPair Left = diameterOptimized(root->left);
    HDPair Right = diameterOptimized(root->right);

    p.height = max(Left.height,Right.height)+1;

    int D1 = Left.height + Right.height;
    int D2 = Left.height;
    int D3 = Right.diameter;

    p.diameter = max(D1,max(D2,D3));

    return p;
}

int main() {
    Node* root = buildTree();
    printPreOrder(root);
    cout << endl;
    printInOrder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    cout << "Height of Tree : " << heightBinaryTree(root) << endl;
    cout << "Diameter of Tree : " << diameter(root) << endl;
    cout << "Optimised Diameter of Tree : " << diameterOptimized(root).diameter << endl;
}
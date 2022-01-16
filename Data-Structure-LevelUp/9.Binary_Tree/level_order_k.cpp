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

void levelOrderPrintK(node* root, int k) {
    queue<node*> q;
    int count = 1;

    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* val = q.front();
        q.pop();
        if (val == NULL) {
            count++;
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
            continue;
        }
        if (count == k) {
            cout << val->data << " ";
        }
        if (val->left) q.push(val->left);
        if (val->right) q.push(val->right);
    }
}

void printKLevel(node* root, int k) {
    if (root == NULL) {
        return;
    }

    if (k == 1) {
        cout << root->data << " ";
    }

    printKLevel(root->left, k - 1);
    printKLevel(root->right, k - 1);
}

int main() {
    // Input : 1 2 4  -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    node* t = buildTree();
    levelOrderPrint(t);
    // Breadth First Search
    levelOrderPrintK(t, 3);
    cout << endl;
    // Depth First Search
    printKLevel(t, 3);
}
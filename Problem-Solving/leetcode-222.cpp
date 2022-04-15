// Count no. of nodes ins a binary tree.

#include <bits/stdc++.h>
using namespace std;

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

Node* buildLevelOrderTree() {
    int d;
    cin >> d;
    Node* root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1) {
            n->left = new Node(c1);
            q.push(n->left);
        }
        if (c2 != -1) {
            n->right = new Node(c2);
            q.push(n->right);
        }
    }
    return root;
}

void printLevelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node* temp = q.front();
        if (temp == NULL) {
            cout << endl;
            q.pop();
            // Insert New Null for next level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            q.pop();
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    return;
}

int countNoOfNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftNodes = countNoOfNodes(root->left);
    int rightNodes = countNoOfNodes(root->right);

    return 1 + leftNodes + rightNodes;
}

int main() {
    Node* root = buildLevelOrderTree();
    printLevelOrder(root);
    cout << countNoOfNodes(root) << endl;
}
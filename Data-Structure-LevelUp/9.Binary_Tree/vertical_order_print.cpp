#include <iostream>
#include <map>
#include <vector>

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

void traverseTree(node* root, int d, map<int, vector<int>>& m) {
    if (root == NULL) {
        return;
    }
    m[d].push_back(root->data);
    traverseTree(root->left, d - 1, m);
    traverseTree(root->right, d + 1, m);
}

void verticalOrderPrint(node* root) {
    map<int, vector<int>> m;
    int d = 0;

    traverseTree(root, d, m);

    for (auto p : m) {
        int key = p.first;
        vector<int> line = p.second;

        for (auto data : line) {
            cout << data << ",";
        }
        cout << endl;
    }

    return;
}

int main() {
    node* t = buildTree();
    verticalOrderPrint(t);
}



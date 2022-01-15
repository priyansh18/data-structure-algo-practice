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

node* buildTreefromLevelOrder() {
    queue<node*> q;

    int data;
    cin >> data;

    node* root = new node(data);

    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1) {
            temp->left = new node(c1);
            q.push(temp->left);
        }
        if (c2 != -1) {
            temp->right = new node(c2);
            q.push(temp->right);
        }
    }

    return root;
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

int main() {
    // Input : 1 2 4  -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    node* t = buildTree();
    levelOrderPrint(t);
    node* v = buildTreefromLevelOrder();
    levelOrderPrint(v);

}
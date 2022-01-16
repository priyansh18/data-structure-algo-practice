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

class Pair {
   public:
    int include;
    int exclude;
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

Pair maxSubsetSum(node* root) {
    Pair p;
    if (root == NULL) {
        p.include = 0;
        p.exclude = 0;

        return p;
    }

    Pair left = maxSubsetSum(root->left);
    Pair right = maxSubsetSum(root->right);

    p.include = root->data + left.exclude + right.exclude;
    p.exclude =
        max(left.include, left.exclude) + max(right.include, right.exclude);

    return p;
}

int main() {
    // Input : 1 2 4  -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    node* t = buildTree();
    levelOrderPrint(t);
    Pair P = maxSubsetSum(t);
    cout << "Max Sum : " << max(P.include, P.exclude) << endl;
}
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

node* minHeightTree(node* root, vector<int> v, int s, int e) {
    if (s > e) {
        return NULL;
    }
    int mid = (s + e) / 2;
    if (root == NULL) {
        root = new node(v[mid]);
    }

    root->left = minHeightTree(root->left, v, s, mid - 1);
    root->right = minHeightTree(root->right, v, mid + 1, e);

    return root;
}

void printTree(node* root, vector<int>& v) {
    if (root == NULL) {
        return;
    }
    printTree(root->left, v);
    v.push_back(root->data);
    cout << root->data << ",";
    printTree(root->right, v);
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
        cout << val->data<<": ";
        cout << "L :  " << (val->left ? val->left->data : -1)<<",";
        cout << "R :  " << (val->right ? val->right->data : -1);
        cout<<endl;
        if (val->left) q.push(val->left);
        if (val->right) q.push(val->right);
    }
}

int main() {
    node* t = buildTree();
    vector<int> v;
    printTree(t, v);
    cout << endl;
    int n = v.size();
    int s = 0;
    int e = n - 1;
    node* root = NULL;
    node* p = minHeightTree(root, v, s, e);
    levelOrderPrint(p);
}
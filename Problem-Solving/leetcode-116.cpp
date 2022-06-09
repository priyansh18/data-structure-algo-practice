// Populating next right pointer in each node

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int val) {
        this->val = val;
        left = right = next = NULL;
    }

    Node* buildTreefromLevelOrder() {
        queue<Node*> q;
        int data;
        cin >> data;
        Node* root = new Node(data);

        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            int c1, c2;
            cin >> c1 >> c2;

            if (c1 != -1) {
                temp->left = new Node(c1);
                q.push(temp->left);
            }
            if (c2 != -1) {
                temp->right = new Node(c2);
                q.push(temp->right);
            }
        }

        return root;
    }
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            auto temp2 = q.front();
            if (temp == NULL) {
                if (!q.empty()) q.push(NULL);
            } else {
                temp->next = temp2;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};

int main() {
    Solution s;
    Node* n;
    Node* root = n->buildTreefromLevelOrder();
    s.connect(root);
}
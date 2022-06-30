// Flatten a Multilevel Doubly Linked List.

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
   public:
    pair<Node*, Node*> helper(Node* head) {
        if (head == NULL) return {NULL, NULL};
        Node* temp = head;

        while (temp) {
            while (temp and temp->child == NULL) {
                temp = temp->next;
            }
            if (temp == NULL) break;
            Node* nextNode = temp->next;
            temp->next = NULL;
            auto llpair = helper(temp->child);
            temp->child = NULL;
            temp->next = llpair.first;
            llpair.first->prev = temp;
            llpair.second->next = nextNode;
            if (nextNode != NULL) {
                nextNode->prev = llpair.second;
            }
            temp = nextNode;
        }

        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
        }

        return {head, tail};
    }

    Node* flatten(Node* head) { return helper(head).first; }
};

int main() {}
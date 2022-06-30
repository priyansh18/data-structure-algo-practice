// Deep Copy with random pointer

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        // It works in three phases.

        // Adding Nodes in between the nodes to copy random pointers
        Node* temp = head;
        while (temp) {
            Node* n = new Node(temp->val);
            n->next = temp->next;
            temp->next = n;
            temp = temp->next->next;
        }
        // copying random pointers of orignal to middle added nodes.
        Node* temp2 = head;
        while (temp2) {
            temp2->next->random =
                temp2->random == NULL ? NULL : temp2->random->next;
            temp2 = temp2->next->next;
        }

        // Seprating middle nodes from orignal list
        Node* oldHead = head;
        Node* newHead = head->next;
        Node* temp3 = newHead;

        while (oldHead and oldHead->next and newHead and newHead->next) {
            oldHead->next = oldHead->next->next;
            newHead->next = newHead->next->next;
            oldHead = oldHead->next;
            newHead = newHead->next;
        }
        oldHead->next = NULL;
        newHead->next = NULL;

        return temp3;
    }
};

int main() {}
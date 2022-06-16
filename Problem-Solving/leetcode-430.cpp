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
    Node* flatten(Node* head) {
        Node* slow = head;
        Node* fast = head;
        fast = fast->next;
        while (!fast->next and !fast->child) {
            while (slow->child == NULL) {
                slow = slow->next;
                fast = fast->next;
            }
            Node* temp2 = slow->child;
            slow->next = temp2;
            temp2->prev = slow;
        }
    }
};

int main() {}
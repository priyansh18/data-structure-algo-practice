// Remove duplicate from sorted linked list

// Merge Sort Linked List.

// Split Circular Linked List into two halves.

#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    int data;
    ListNode* next;
    ListNode(int d) {
        data = d;
        next = NULL;
    }
};

void insertionAtTail(ListNode*& head, int data) {
    if (head == NULL) {
        ListNode* n = new ListNode(data);
        head = n;
        return;
    }

    ListNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    ListNode* n = new ListNode(data);
    temp->next = n;
    n->next = NULL;
}

void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->data << "--->";
        head = head->next;
    }
}

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode*& head) {
        if (head == NULL or head->next == NULL) {
            return head;
        }

        ListNode* temp = head;
        ListNode* temp2 = temp->next;

        while (temp2) {
            if (temp->data == temp2->data) {
                ListNode* n = temp2;
                temp2 = temp2->next;
                delete n;
            } else {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }
        temp->next=NULL;

        return head;
    }
};

int main() {
    Solution s;
    ListNode* head = NULL;
    insertionAtTail(head, 4);
    insertionAtTail(head, 5);
    insertionAtTail(head, 5);
    insertionAtTail(head, 6);
    insertionAtTail(head, 7);
    insertionAtTail(head, 7);
    insertionAtTail(head, 8);
    insertionAtTail(head, 8);
    printLL(head);
    cout << endl;
    s.deleteDuplicates(head);
    printLL(head);
}
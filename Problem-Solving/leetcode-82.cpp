// Remove Duplicates from sorted list

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next =head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            while (curr->next and prev->next->data == curr->next->data) {
                curr = curr->next;
            }

            if (prev->next == curr) {
                prev = curr;
            } else {
                prev->next = curr->next;
            }
            curr = curr->next;
        }

        return dummy->next;
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
    ListNode* result = s.deleteDuplicates(head);
    printLL(result);
}
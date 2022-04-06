// Odd Even Linked list.

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL or head->next == NULL) {
            return head;
        }

        ListNode* temp = head;
        ListNode* temp2 = head->next;
        ListNode* head2 = temp2;

        while (temp and temp->next and temp2 and temp2->next) {
            temp->next = temp->next->next;
            temp = temp->next;
            temp2->next = temp2->next->next;
            temp2 = temp2->next;
        }
        temp->next = head2;

        return head;
    }
};

int main() {
    Solution s;
    ListNode* head = NULL;
    insertionAtTail(head, 1);
    insertionAtTail(head, 2);
    insertionAtTail(head, 3);
    insertionAtTail(head, 4);
    insertionAtTail(head, 5);
    printLL(head);
    cout << endl;
    s.oddEvenList(head);
    printLL(head);
}
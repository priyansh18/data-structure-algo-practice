// Middle of linked list.

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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main() {
    Solution s;
    ListNode* head = NULL;
    insertionAtTail(head, 9);
    insertionAtTail(head, 8);
    insertionAtTail(head, 7);
    insertionAtTail(head, 6);
    insertionAtTail(head, 5);
    insertionAtTail(head, 4);

    cout << s.middleNode(head)->data << endl;
}
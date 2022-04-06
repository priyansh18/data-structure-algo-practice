// Merge two sorted linked list.

// Split Circular Linked List into two halves.

#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode(int d) {
        val = d;
        next = NULL;
    }
};

void insertionAtTail(ListNode*& head, int val) {
    if (head == NULL) {
        ListNode* n = new ListNode(val);
        head = n;
        return;
    }

    ListNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    ListNode* n = new ListNode(val);
    temp->next = n;
    n->next = NULL;
}

void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->val << "--->";
        head = head->next;
    }
}

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* temp = NULL;
        if (list1->val <= list2->val) {
            temp = list1;
            list1 = list1->next;
        } else {
            temp = list2;
            list2 = list2->next;
        }

        ListNode* newHead = temp;
        while (list1 and list2) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }

        if (list1 == NULL)
            temp->next = list2;
        else
            temp->next = list1;
        return newHead;
    }
};

int main() {
    Solution s;
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    insertionAtTail(head1, 1);
    insertionAtTail(head1, 2);
    insertionAtTail(head1, 4);
    insertionAtTail(head2, 1);
    insertionAtTail(head2, 3);
    insertionAtTail(head2, 4);
    printLL(head1);
    cout << endl;
    printLL(head2);
    cout << endl;

    ListNode* result = s.mergeTwoLists(head1, head2);
    printLL(result);
}

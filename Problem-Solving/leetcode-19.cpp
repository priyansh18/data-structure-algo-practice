// Remove Nth Node from the end of Linked List.

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

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = 0;

        while (temp) {
            length++;
            temp = temp->next;
        }

        int val = length - n;

        if (val == 0) {
            head = head->next;
        } else {
            ListNode* temp1 = head;

            while (--val) {
                temp1 = temp1->next;
            }

            temp1->next = temp1->next->next;

            return head;
        }
    }

    ListNode* removeNthFromEndSingleTraversal(ListNode* head, int n) {
        ListNode* second = head;
        ListNode* first = head;

        while (n--) {
            first = first->next;
        }

        while (first and first->next) {
            second = second->next;
            first = first->next;
        }

        if (first == NULL) {
            head = head->next;
        } else {
            second->next = second->next->next;
        }

        return head;
    }

    void printLL(ListNode* head) {
        while (head != NULL) {
            cout << head->data << "--->";
            head = head->next;
        }
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
    ListNode* result = s.removeNthFromEnd(head, 2);
    s.printLL(result);
    cout << endl;
    ListNode* result2 = s.removeNthFromEndSingleTraversal(head, 2);
    s.printLL(result2);
}
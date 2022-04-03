// Add two numbers.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* result = NULL;
        int quotient = 0;

        while (temp1 and temp2) {
            int val = temp1->data + temp2->data + quotient;
            insertionAtTail(result, val % 10);
            quotient = val / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1) {
            while (temp1) {
                int val = temp1->data + quotient;
                insertionAtTail(result, val % 10);
                quotient = val / 10;
                temp1 = temp1->next;
            }
        }

        if (temp2) {
            while (temp2) {
                int val = temp2->data + quotient;
                insertionAtTail(result, val % 10);
                quotient = val / 10;
                temp2 = temp2->next;
            }
        }

        if (quotient > 0) {
            insertionAtTail(result, quotient);
        }

        return result;
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
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    insertionAtTail(head1, 2);
    insertionAtTail(head1, 4);
    insertionAtTail(head1, 3);
    insertionAtTail(head2, 5);
    insertionAtTail(head2, 6);
    insertionAtTail(head2, 4);
    s.printLL(head1);
    cout << endl;
    s.printLL(head2);
    cout << endl;
    ListNode* result = s.addTwoNumbers(head1, head2);
    s.printLL(result);
}
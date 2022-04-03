// Alternative splitting the linked list.

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

void insertionAtTail(ListNode*& head, int d) {
    if (head == NULL) {
        ListNode* n = new ListNode(d);
        head = n;
        return;
    }

    ListNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    ListNode* n = new ListNode(d);
    temp->next = n;
    n->next = NULL;
    return;
}

void insertionAtHead(ListNode*& head, int d) {
    if (head == NULL) {
        ListNode* n = new ListNode(d);
        head = n;
        return;
    }

    ListNode* n = new ListNode(d);
    n->next = head;
    head = n;
    return;
}

void printLL(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->data << "--->";
        temp = temp->next;
    }
}

class Solution {
   public:
    pair<ListNode*, ListNode*> alternateLL(ListNode* head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        ListNode* a = NULL;
        ListNode* b = NULL;

        while (temp1 and temp1->next) {
            insertionAtTail(a, temp1->data);
            temp1 = temp1->next->next;
        }

        while (temp2 and temp2->next) {
            insertionAtTail(b, temp2->next->data);
            temp2 = temp2->next->next;
        }

        return make_pair(a, b);
    }
};

int main() {
    Solution s;
    ListNode* head = NULL;
    insertionAtTail(head, 4);
    insertionAtTail(head, 5);
    insertionAtTail(head, 6);
    insertionAtTail(head, 7);
    insertionAtTail(head, 8);
    insertionAtHead(head, 3);
    insertionAtHead(head, 2);
    insertionAtHead(head, 1);
    printLL(head);
    cout << endl;
    auto [head1,head2] = s.alternateLL(head);
    printLL(head1);
    cout << endl;
    printLL(head2);
}
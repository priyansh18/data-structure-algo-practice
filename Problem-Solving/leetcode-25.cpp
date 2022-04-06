// Reverse Node in K-Group

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

ListNode* reverseLL(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int findLength(ListNode* head) {
    ListNode* temp = head;
    int length = 0;
    while (temp) {
        length++;
        temp = temp->next;
    }
    return length;
}

ListNode* reverseKGroupLL(ListNode* head, int k, int length) {
    if (length < k) {
        return head;
    }
    int count = 0;
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while (count < k and curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next) {
        head->next = reverseKGroupLL(next, k, length - k);
    }

    return prev;
}

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = findLength(head);
        return reverseKGroupLL(head, k, length);
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
    printLL(head);
    cout << endl;
    ListNode* res = s.reverseKGroup(head, 3);
    printLL(res);
}
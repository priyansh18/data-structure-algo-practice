// Reverse a linked list.

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next;
        ListNode* current = head;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
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
    ListNode* reverseHead =  s.reverseList(head);
    printLL(reverseHead);
    // cout << s.isPalindrome(head) << endl;
}
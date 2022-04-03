// Cycle Detection in singly linked list
// Floyd Cycle Detection,hare & tortoise Algo,Fast & Slow Pointer Approach.

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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && slow && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }

        return false;
    }
};

int main() {
    Solution s;
    ListNode* head = NULL;
    insertionAtTail(head, 9);
    insertionAtTail(head, 8);
    insertionAtTail(head, 7);
    ListNode* temp = head;
    insertionAtTail(head, 6);
    insertionAtTail(head, 5);
    insertionAtTail(head, 4);
    head->next = temp;
    cout << s.hasCycle(head) << endl;
}
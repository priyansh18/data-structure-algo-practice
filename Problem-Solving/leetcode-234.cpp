// Palindrome Linked List

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
    void reverse(ListNode*& head) {
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
    }

    int compare(ListNode* temp1, ListNode* temp2) {
        while (temp1 and temp2) {
            if (temp1->data == temp2->data) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else {
                return 0;
            }
        }
        if (temp1 == NULL and temp2 == NULL) {
            return 1;
        }

        return 0;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == NULL or head->next == NULL) {
            return true;
        }
        // 1. Reach the middle of the linked list.
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* previousSlow = head;
        ListNode* midNode = NULL;

        while (fast and fast->next) {
            fast = fast->next->next;
            previousSlow = slow;
            slow = slow->next;
        }
        // If length of ll is odd.
        if (fast) {
            midNode = slow;
            slow = slow->next;
        }

        // Slow is Pointing to middle next node of linked list.

        // 2. Reverse the second half of linked list.
        ListNode* temp = slow;
        previousSlow->next = NULL;
        reverse(temp);
        int result = compare(head, temp);
        reverse(temp);

        if (midNode) {
            previousSlow->next = midNode;
            midNode->next = temp;
        } else {
            previousSlow->next = temp;
        }

        return result;
    }
};

int main() {
    Solution s;
    ListNode* head = NULL;
    insertionAtTail(head, 1);
    insertionAtTail(head, 2);
    insertionAtTail(head, 3);
    insertionAtTail(head, 4);
    insertionAtTail(head, 1);
    cout << s.isPalindrome(head) << endl;
}

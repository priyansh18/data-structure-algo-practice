//  Intersection of two linked list.

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
    void printLL(ListNode* head) {
        while (head != NULL) {
            cout << head->data << "--->";
            head = head->next;
        }
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lengthA = 0;
        int lengthB = 0;

        ListNode* tempA = headA;
        while (tempA) {
            lengthA++;
            tempA = tempA->next;
        }

        ListNode* tempB = headB;
        while (tempB) {
            lengthB++;
            tempB = tempB->next;
        }

        int diff = abs(lengthA - lengthB);

        ListNode* tempAA = headA;
        ListNode* tempBB = headB;

        if (lengthA > lengthB) {
            while (diff--) {
                tempAA = tempAA->next;
            }
        } else {
            while (diff--) {
                tempBB = tempBB->next;
            }
        }

        while (tempAA != NULL and tempBB!= NULL) {
            if (tempAA == tempBB) {
                return tempAA;
            }
            tempAA = tempAA->next;
            tempBB = tempBB->next;
        }

        return NULL;
    }
};

int main() {
    Solution s;
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    insertionAtTail(head1, 2);
    insertionAtTail(head1, 3);
    insertionAtTail(head1, 4);
    insertionAtTail(head1, 5);

    ListNode* temp = head1;
    while (temp->next) {
        temp = temp->next;
    }

    insertionAtTail(head1, 6);
    insertionAtTail(head2, 1);
    insertionAtTail(head2, 3);
    ListNode* temp2 = head2;
    while (temp2->next) {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    s.printLL(head1);
    cout << endl;
    s.printLL(head2);
    cout << endl;
    ListNode* res = s.getIntersectionNode(head1, head2);
    cout << res->data << endl;
}
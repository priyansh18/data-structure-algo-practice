//  Rotate List

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL or head->next == NULL or k == 0) return head;

        // Calculating length.
        ListNode* temp = head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }

        //  Finding new head
        int rotateBy = k % length;
        if (rotateBy == 0) return head;
        int val = length - rotateBy;

        ListNode* temp2 = head;
        while (--val) {
            temp2 = temp2->next;
        }

        ListNode* newHead = temp2->next;
        temp2->next = NULL;

        //  Find tail to connect head too
        ListNode* temp3 = newHead;
        while (temp3->next) {
            temp3 = temp3->next;
        }
        temp3->next = head;

        return newHead;
    }
};

int main() {}
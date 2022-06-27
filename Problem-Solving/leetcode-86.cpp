// Partition List

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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;

        ListNode* smallerTail = NULL;
        ListNode* biggerTail = NULL;
        ListNode* smallerHead = NULL;
        ListNode* biggerHead = NULL;

        while (head) {
            if (head->val < x) {
                if (smallerTail == NULL) {
                    smallerTail = smallerHead = head;
                } else {
                    smallerTail->next = head;
                    smallerTail = smallerTail->next;
                }
            } else {
                if (biggerTail == NULL) {
                    biggerTail = biggerHead = head;
                } else {
                    biggerTail->next = head;
                    biggerTail = biggerTail->next;
                }
            }
            head = head->next;
        }

        if (smallerHead and biggerHead == NULL) {
            return smallerHead;
        }

        if (smallerHead == NULL and biggerHead) {
            return biggerHead;
        }

        smallerTail->next = biggerHead;
        biggerTail->next = NULL;
        return smallerHead;
    }
};

int main() {}
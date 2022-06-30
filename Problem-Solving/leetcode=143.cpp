// Reorder List

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
    ListNode* reverse(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* reversedHead = reverse(slow->next);
        slow->next = NULL;

        ListNode* temp = head;

        while (temp and reverseHead) {
            ListNode* headNext = temp->next;
            ListNode* reverseHeadNext = reversedHead->next;
            temp->next = reversedHead;
            reversedHead->next = headNext;
            temp = headNext;
            reversedHead = reversedHead->next;
        }

        return head;
    }
};

int main() {}
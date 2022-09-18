// Reverse Node in K-Group

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL or head->next == NULL) return head;
        int x = k;
        ListNode* temp = head;
        while (--x and temp) {
            temp = temp->next;
        }
        if (temp == NULL) {
            return head;
        }
        ListNode* remainingHead = temp->next;
        ListNode* tail = head;
        temp->next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        tail->next = reverseKGroup(remainingHead, k);

        return prev;
    }
};

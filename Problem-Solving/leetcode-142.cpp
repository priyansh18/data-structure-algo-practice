// Linked List Cycle II

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL or head->next == NULL) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};

int main() {}
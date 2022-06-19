// Swap Nodes in Pair

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        ListNode* ll = swapPairs(head->next->next);
        ListNode* temp = head->next;
        temp->next = head;
        head->next = ll;
        head = temp;

        return head;
    }
};

int main() {}
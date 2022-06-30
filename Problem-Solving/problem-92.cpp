// Reverse Linked list II

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
    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        if (head == NULL) return {};
        if (head->next == NULL) return {head, head};

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* temp = prev;
        while (temp) {
            temp = temp->next;
        }

        return {prev, temp};
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL or head->next == NULL) return NULL;
        ListNode* temp = head;
        ListNode* beforeLeft = NULL;
        while (--left) {
            beforeLeft = temp;
            temp = temp->next;
        }

        ListNode* newHead = temp;

        int val = right - left;
        while (val--) {
            temp = temp->next;
        }

        ListNode* afterRight = temp->next;
        temp->next = NULL;

        auto llPair = reverse(newHead);

        llPair.second->next = afterRight;

        if (beforeLeft == NULL) {
            return llPair.first;
        } else {
            beforeLeft->next = llPair.first;
        }
        return head;
    }
};

int main() {}
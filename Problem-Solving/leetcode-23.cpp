// Merge K Sorted Linked List

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Compare {
   public:
    bool operator()(ListNode* A, ListNode* B) { return A->val > B->val; }
};

class Solution {
   public:
    void insertionAtTail(ListNode*& head, ListNode* n) {
        if (head == NULL) {
            ListNode* a = new ListNode(n->val);
            head = a;
            return;
        }
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        ListNode* a = new ListNode(n->val);
        temp->next = a;
        return;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        int m = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, Compare> q;
        for (int i = 0; i < m; i++) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }
        while (!q.empty()) {
            auto temp = q.top();
            q.pop();
            if (temp and temp->next) {
                insertionAtTail(head, temp);
                q.push(temp->next);
            } else {
                if (temp) insertionAtTail(head, temp);
            }
        }

        return head;
    }
};

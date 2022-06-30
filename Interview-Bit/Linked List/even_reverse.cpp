#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseLL(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

ListNode* Solution::solve(ListNode* A) {
    if (A == NULL or A->next == NULL) return A;
    ListNode* temp = A;
    ListNode* oddLL = NULL;
    ListNode* evenLL = NULL;

    while (temp and temp->next) {
        if (oddLL == NULL) {
            oddLL = temp;
        } else if (oddLL != NULL) {
            oddLL->next = temp;
        }

        if (evenLL == NULL) {
            evenLL = temp->next;
        } else if (eveLL != NULL) {
            temp = temp->next->next;
        }
    }

    ListNode* evenReverseHead = reverseLL(evenLL);

    ListNode* temp2 = head;

    while (temp2 and evenReverseHead) {
        ListNode* nextEvenReverseHead = evenReverseHead->next;
        ListNode* nextTemp2 = temp2->next;
        temp2->next = nextEvenReverseHead;
        evenReverseHead->next = nextTemp2;
        evenReverseHead = nextEvenReverseHead;
        temp2 = nextTemp2;
    }

    return head;
}

int main() {}
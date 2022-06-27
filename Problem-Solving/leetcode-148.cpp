// Sort Linked list

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* n = new ListNode(-1);
        ListNode* temp = n;
        while (left and right) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        while (left) {
            temp->next = left;
            left = left->next;
        }

        while (right) {
            temp->next = right;
            right = right->next;
        }

        return n->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL) return;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }


        ListNode* sortLeft = sortList(head);
        ListNode* sortRight = sortList(slow->next);
        slow->next = NULL;

        ListNode* newHead = mergeList(sortLeft, sortRight);

        return newHead;
    }
};

int main() {
    Solution s;
    ListNode* root = s.sortList(head);
}
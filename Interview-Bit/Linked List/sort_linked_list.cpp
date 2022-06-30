/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* newHead = NULL;
    ListNode* newTail = NULL;
    
    while(list1 != NULL and list2 != NULL){
        if(newHead == NULL){
            if(list1->val < list2->val){
                newHead = newTail = list1;
                list1 = list1->next;
            }else{
                newHead = newTail = list2;
                list2 = list2->next;
            }
        }else{
            if(list1->val < list2->val){
                newTail->next = list1;
                newTail = newTail->next;
                list1  = list1->next;
            }else{
                newTail->next = list2;
                newTail = newTail->next;
                list2 = list2->next;
            }
        }
    }
    
    if(list1 == NULL and list2 == NULL) return newHead;
    
    if(list1 == NULL) {
        if(newHead == NULL) return list2;
        newTail->next = list2;
        return newHead;
    }
    
    if(newHead == NULL) return list1;
    newTail->next = list1;
    return newHead;
}
    
ListNode* findMiddleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode* Solution::solve(ListNode* head) {
    if(head == NULL) return head;
        if(head->next == NULL) return head;
        
        ListNode* middleNode = findMiddleNode(head);
        ListNode* secondHead = middleNode->next;
        middleNode->next = NULL;
        
        ListNode* leftSortedList =  sortList(head);
        ListNode* rightSortedList = sortList(secondHead);
        return mergeTwoLists(leftSortedList, rightSortedList);
}
// Insertion Sort List

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
    void print(ListNode* head){
        cout<<endl;
        while(head) {cout<<head->val<<" ";head=head->next;}
        cout<<endl;
    }
    
    ListNode* insert(ListNode* node, ListNode* head) {
        if(node->val < head->val){
            node->next=head;
            head = node;
            return head;
        }else{
            ListNode* temp = head;
            ListNode* prev = NULL;
            while(temp  and temp->val <= node->val){
                prev = temp;
                temp = temp->next;
            }
            
            if(temp){
                node->next = prev->next;
                prev->next = node;
                return head;
            }else{
                prev->next= node;
                return head;
            }
            
            assert("Error");
            return head;
        }
       
    }

    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        
        ListNode* unSortedHead = head->next;
        ListNode* sortedHead = head;
        sortedHead->next=NULL;
        
        while(unSortedHead){
            ListNode* node = unSortedHead;
            unSortedHead = unSortedHead->next;
            node->next=NULL;
            sortedHead = insert(node,sortedHead);
            
        }
        
        return sortedHead;
    }
};
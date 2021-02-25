// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* C = head;
        ListNode* P = NULL;
        ListNode* N;
        
        while(C != NULL){
            // save the next node
            N = C->next;
            // make the current node point to previous
            C->next = P;
            
            // update P and C take them 1 step forward
            P = C;
            C = N;
        }
        head = P;
        return head;
    }
};


// Another way of writing (PCN Approach)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        
        ListNode* P = ans;
        ListNode* C = P->next;
        ListNode* N = C->next;
        
        while(N->next != NULL){
            C->next = N->next;
            N->next = P->next;
            P->next = N;
            N = C->next;
        }
        N->next = P->next;
        P->next = N;
        C->next = NULL;
        
        return ans->next;
    }
};

// https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(head == NULL) return head;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        
        ListNode* P = ans;
        for(int i=0;i<l-1;i++){
            P = P->next;
        }
        ListNode* C = P->next;
        ListNode* N = C->next;
        
        for(int i=0; i<r-l;i++){
            // save the next node of N-node
            C->next = N->next;
            
            // Connect N-node to start of the sub-list i.e. next of prev
            N->next = P->next;
            
            // Connect prev node to this new start node of sub list
            P->next = N;
            
            // Update N for next iteration
            N = C->next;
        }
        
        return ans->next;
    }
};

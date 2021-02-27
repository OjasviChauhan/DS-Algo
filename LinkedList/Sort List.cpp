// https://leetcode.com/problems/sort-list/

class Solution {
public:
    // Finding midpoint of list using runner technique
    ListNode* midpoint(ListNode* head){
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    // Merge two sorted lists
    ListNode* merge(ListNode* a, ListNode* b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode* c;
        if(a->val < b->val){
            c = a;
            c->next = merge(a->next, b);
        }
        else{
            c = b;
            c->next = merge(a,b->next);
        }
        return c;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        ListNode* mid = midpoint(head);
        ListNode* a = head;
        ListNode* b = mid->next;
        mid->next = NULL;
        
        a = sortList(a);
        b = sortList(b);
        
        return merge(a,b);
    }
};

// 1. https://leetcode.com/problems/add-two-numbers/
// 2. https://leetcode.com/problems/add-two-numbers-ii/

// SOLUTION 1
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* t3 = new ListNode();
        ListNode* ans = t3;
        
        int carry = 0;   
        while(t1 != NULL and t2 != NULL){
            int x = t1->val + t2->val + carry;
            if(x%10 == x){
                carry = 0;
                t3->next = new ListNode(x);
            }
            else{
                carry = 1;
                t3->next = new ListNode(x%10);
            }
            t1 = t1->next;
            t2 = t2->next;
            t3 = t3->next;
        }
        while(t1 != NULL){
            int x = t1->val + carry;
            if(x%10 == x){
                carry = 0;
                t3->next = new ListNode(x);
            }
            else{
                carry = 1;
                t3->next = new ListNode(x%10);
            }
            t1 = t1->next;
            t3 = t3->next;
        }
        while(t2 != NULL){
            int x = t2->val + carry;
            if(x%10 == x){
                carry = 0;
                t3->next = new ListNode(x);
            }
            else{
                carry = 1;
                t3->next = new ListNode(x%10);
            }
            t2 = t2->next;
            t3 = t3->next;
        }
        if(carry == 1){
            t3->next = new ListNode(1);
        }
        return ans->next;
    }
};

//SOLUTION 2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* C = head;
        ListNode* P = NULL;
        ListNode* N;
        
        while(C != NULL){
            N = C->next;
            C->next = P;
            P = C;
            C = N;
        }
        head = P;
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = reverseList(l1);
        ListNode* t2 = reverseList(l2);
        ListNode* t3 = new ListNode();
        ListNode* ans = t3;
        
        int carry = 0;   
        while(t1 != NULL and t2 != NULL){
            int x = t1->val + t2->val + carry;
            if(x%10 == x){
                carry = 0;
                t3->next = new ListNode(x);
            }
            else{
                carry = 1;
                t3->next = new ListNode(x%10);
            }
            t1 = t1->next;
            t2 = t2->next;
            t3 = t3->next;
        }
        while(t1 != NULL){
            int x = t1->val + carry;
            if(x%10 == x){
                carry = 0;
                t3->next = new ListNode(x);
            }
            else{
                carry = 1;
                t3->next = new ListNode(x%10);
            }
            t1 = t1->next;
            t3 = t3->next;
        }
        while(t2 != NULL){
            int x = t2->val + carry;
            if(x%10 == x){
                carry = 0;
                t3->next = new ListNode(x);
            }
            else{
                carry = 1;
                t3->next = new ListNode(x%10);
            }
            t2 = t2->next;
            t3 = t3->next;
        }
        if(carry == 1){
            t3->next = new ListNode(1);
        }
        return reverseList(ans->next);
    }
};

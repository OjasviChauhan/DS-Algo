// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

class Solution {
public:
    int length(ListNode* head){
        int cnt = 0;
        while(head!=NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int len = length(head);
        if(len == 1) return head;
        
        if(k==1){
            ListNode* c1 = head;
            ListNode* c2 = head;
            while(c2->next != NULL){
                c2 = c2->next;
            }
            swap(c1->val, c2->val);
            return head;
        }
        
        int s = k-1;
        int e = len - k;
        ListNode* c1 = head;
        ListNode* c2 = head;
        
        while(s--) c1 = c1->next;
        while(e--) c2 = c2->next;
        swap(c1->val, c2->val);
        
        return head;
    }
};

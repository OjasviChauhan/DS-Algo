class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL or head->next == NULL){
            return head;
        }
        
        ListNode* shead = reverseList(head->next);
        ListNode* temp = head->next;
        temp->next = head;
        head->next = NULL;
        
        return shead;
    }
};

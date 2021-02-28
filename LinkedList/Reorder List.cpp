// https://www.interviewbit.com/problems/reorder-list/

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
    
ListNode* reverse(ListNode* head){
    if(head==NULL or head->next==NULL){
            return head;
    }
    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
        
    return newHead;
}
    
ListNode* Solution::reorderList(ListNode* head) {
    if(head==NULL or head->next==NULL){
        return head;
    }
    ListNode* prev = midpoint(head);
    ListNode* mid = prev->next;
    prev->next = NULL;
        
    ListNode* l1 = head;
    ListNode* l2 = reverse(mid);
        
    while(l2 and l1){
        ListNode* l2next = l2->next;
        l2->next = l1->next;
        l1->next = l2;
        l2 = l2next;
        l1 = l1->next->next;
    }
    return head;
}

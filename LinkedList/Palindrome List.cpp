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

int Solution::lPalin(ListNode* A) {
    ListNode* t = A;
    ListNode* copy = new ListNode(A->val);
    ListNode* head = copy;
    t = t->next;
    while(t){
        copy->next= new ListNode(t->val);
        t = t->next;
        copy = copy->next;
    }
    
    ListNode* rev = reverseList(A);
    while(head and rev){
        if(head->val != rev->val) return 0;
        head = head->next;
        rev = rev->next;
    }
    return 1;
}

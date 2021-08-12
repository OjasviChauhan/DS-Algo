// https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

ListNode* Solution::solve(ListNode* head, int k) {
    ListNode* ans = new ListNode(0);
    ListNode* p = NULL;
    ListNode* c = head; 
    ListNode* n;
    ListNode* start;
    head = ans;
    int t = k;
    int flag = 1;

    while(c){
        if(flag % 2 != 0){
            start = c;
            while(t-- and c){
                n = c->next;
                c->next = p;
                p = c;
                c = n;
            }
            t = k;
            ans->next = p;
            ans = start;
            p = NULL;
            flag = 2;
        }
        else{
            ans->next = c;
            while(t-- and c){
                p = c;
                c = c->next;
            }
            t = k;
            ans = p;
            p = NULL;
            flag = 1;
        }
    }
    return head->next;
}

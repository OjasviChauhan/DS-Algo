// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#

class Solution {
    public:
    struct node *reverse (struct node *head, int k) { 
        node* ans = new node(0);
        node* p = NULL; 
        node* c = head; 
        node* n; 
        node* start;
        head = ans;
        
        int t = k;
        while(c){
            start = c;
            while(c and t--){
                n = c->next;
                c->next = p;
                p = c;
                c = n;
            }
            t = k;
            ans->next = p;
            ans = start;
            p = NULL;
        }
        return head->next;
    }
};

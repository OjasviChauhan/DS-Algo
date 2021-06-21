// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_set<int> s;
        Node* i = head;
        Node* j = i;
        s.insert(i->data);
        
        while(j->next and i){
            j = j->next;
            if(s.find(j->data) != s.end()){
                while(j and s.find(j->data) != s.end()) 
                    j = j->next;
                i->next = j;
                if(j != NULL) s.insert(j->data);
            }
            else s.insert(j->data);
            if(i != NULL) i = i->next;
            if(j == NULL) break;
        }
        return head;
    }
};

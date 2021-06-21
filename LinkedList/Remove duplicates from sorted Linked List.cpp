Node *removeDuplicates(Node *head)
{
    Node* i = head;
    Node* j = i->next;
    
    while(j and i){
        if(i->data == j->data){
            while(j and i->data == j->data){
                j = j->next;
            }
            i->next = j;
        }
        if(j != NULL) j = j->next;
        if(i != NULL) i = i->next;
    }
    return head;
}

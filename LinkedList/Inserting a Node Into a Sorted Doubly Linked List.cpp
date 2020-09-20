/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    bool flag = true;
    DoublyLinkedListNode *temp = head;
    DoublyLinkedListNode *newnode = new DoublyLinkedListNode(data);
    if(data < head->data){
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    else{
        while(temp->next != NULL){
            if(temp->data > data){
                DoublyLinkedListNode *previous = temp->prev;
                newnode->next = temp;
                temp->prev = newnode;
                previous->next = newnode;
                newnode->prev = previous;
                break;
            }
            temp = temp->next;
        }
    }
    if(data < temp->data){
        DoublyLinkedListNode *prevtemp = temp->prev;
        prevtemp->next = newnode;
        newnode->prev = prevtemp;
        newnode->next = temp;
        temp->prev = newnode;
    }
    else{
        newnode->next = NULL;
        temp->next = newnode;
        newnode->prev = temp;
    }
    return head;
}

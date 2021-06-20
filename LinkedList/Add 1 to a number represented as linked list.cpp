// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#

class Solution {
    public:
    Node* addOne(Node *head){
        Node* t = head;
        Node* non_nine;
        bool flag = false;
        int len = 0;
        
        while(t){
            if(t->data != 9) flag = true, non_nine = t;
            t = t->next;
            len++;
        }
        if(flag){
            non_nine->data = non_nine->data + 1;
            Node* k;
            
            if(non_nine->next != NULL){
                k = non_nine->next;
                while(k){
                    k->data = 0;
                    k = k->next;
                }
            }
        }
        else{
            Node* temp = head;
            while(temp){
                temp->data = 0;
                temp = temp->next;
            }
            Node* nn = new Node(1);
            nn->next = head;
            return nn;
        }
        return head;
    }
};

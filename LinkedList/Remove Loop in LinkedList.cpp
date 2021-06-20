// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* fast = head;
        Node* slow = head;
        bool flag = false;
        
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow){
                flag = true;
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                break;
            }
        }
        if(flag){
            Node* ans = slow;
            while(ans->next != slow){
                ans = ans->next;
            }
            ans->next = NULL;
        }
    }
};

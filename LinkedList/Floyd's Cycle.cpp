// https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            // when you find cycle then reset slow pointer to head and start moving both slow and fast
            // The very first node where they'll meet would be the begining of cycle.
            if(fast == slow){
                slow = head;
                while(slow != fast){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

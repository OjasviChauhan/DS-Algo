// https://leetcode.com/problems/intersection-of-two-linked-lists/

/*
We can use two iterations to do that. In the first iteration, we will reset the pointer of one linkedlist
to the head of another linkedlist after it reaches the tail node. In the second iteration, we will move two
pointers until they points to the same node. Our operations in first iteration will help us counteract the 
difference. So if two linkedlist intersects, the meeting point in second iteration must be the intersection 
point. If the two linked lists have no intersection at all, then the meeting pointer in second iteration must
be the tail node of both lists, which is null
*/

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
        if(A == NULL or B == NULL) return NULL;
        
        ListNode* a = A;
        ListNode* b = B;
        
        while(a != b){
            a = a==NULL ? B : a->next;
            b = b==NULL ? A : b->next;
        }
        return a;
    }
};

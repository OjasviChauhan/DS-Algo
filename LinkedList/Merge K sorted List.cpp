
// https://leetcode.com/problems/merge-k-sorted-lists/

typedef pair<int, ListNode*> pi;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return {};
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        ListNode* ans = new ListNode();
        
        for(int r = 0; r < lists.size(); r++) {
            ListNode* list = lists[r];
            if(list) pq.push({list->val, list});
        }
        
        ListNode* res = ans;
        while(!pq.empty()) {
            pi top = pq.top();
            pq.pop();
            int data = top.first;
            ListNode* t = top.second;
            
            res->next = new ListNode(data);
            if(t->next){
                t = t->next;
                pq.push({t->val, t});
            }
            res = res->next;
        }
        
        return ans->next;
    }
};

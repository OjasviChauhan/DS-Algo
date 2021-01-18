// https://leetcode.com/problems/course-schedule-ii/

// Here time complexity is O(NlogN) due to use of reverse function for vector.
// This could be optimized by using the list instead of vector and push_front in that.

class Solution {
public:
    vector<int> l[20001];
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        // if there is no prerequisites then return all nodes
        if(prerequisites.size()==0){
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
            return ans;
        }
        
        // making adjacency list
        for(auto x : prerequisites){
            l[x[0]].push_back(x[1]);
        }
        
        // calculating in-degrees of all nodes
        vector<int> indeg(n,0);
        for(vector<int> v:l){
            for(int i:v){
                indeg[i]++;
            }
        }
        
        // making queue and pushing all nodes with 0 in-degree
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto nbr:l[node]){
                // decrement the nbrs of node(0 indeg) by factor of 1
                indeg[nbr]--;
                if(indeg[nbr]==0) q.push(nbr);
            }
        }
        
        // reversing the order to get the correct topological sort
        reverse(ans.begin(),ans.end());
        // if final ans does not have all nodes of graph it means that contains cycle
        // and thus reaching all nodes is impossible.
        if(ans.size() != n) ans.clear();
        return ans;
    }
};

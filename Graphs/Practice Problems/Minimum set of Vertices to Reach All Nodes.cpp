// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

// Just return the nodes with 0 in-degrees.

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int>f(n);
        
        for(auto p:edges){
            f[p[1]]++;
        }
        
        for(int i=0;i<n;i++){
            if(f[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

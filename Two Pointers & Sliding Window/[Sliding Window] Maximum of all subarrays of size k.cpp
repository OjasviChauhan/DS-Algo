// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        if(k==1) return arr;
        int n = arr.size();
        list<int> l;
        vector<int> ans;
        int i=0,j=0;

        for(j=0;j<k;j++){
            while(!l.empty() and l.back() < arr[j]){
                l.pop_back();
            }
            l.push_back(arr[j]);
        }
        ans.push_back(l.front());
        
        while(j<n){
            if(arr[i] == l.front()){
                l.pop_front();
            }
            while(!l.empty() and l.back() < arr[j]){
                l.pop_back();
            }
            l.push_back(arr[j]);
            ans.push_back(l.front());
            
            i++;
            j++;
        }
        return ans;
    }
};

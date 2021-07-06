// https://leetcode.com/problems/next-greater-element-ii/submissions/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        stack<int> s;
        vector<int> v;

        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                int j;
                for(j=0;j<n;j++){
                    if(A[j] > A[i]){
                        v.push_back(A[j]);
                        s.push(A[j]);
                        break;
                    }
                }
                if(j==n) v.push_back(-1);
            }
            
            else if(!s.empty() and A[i] < s.top()){
                v.push_back(s.top());
            }
            
            else if(!s.empty() and A[i] >= s.top()){
                while(!s.empty() and s.top() <= A[i]){
                    s.pop();
                }
                if(!s.empty()){
                    v.push_back(s.top());
                }
                else{
                    int j;
                    for(j=0;j<n;j++){
                        if(A[j] > A[i]){
                            v.push_back(A[j]);
                            s.push(A[j]);
                            break;
                        }
                    }
                    if(j==n) v.push_back(-1);
                }
            }
            s.push(A[i]);
        }
        reverse(v.begin(),v.end());        
        return v;
    }
};

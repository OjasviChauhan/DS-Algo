// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int start=0,end=0,count=K;
        int len = -1;
        
        for(end=0;end<A.size();end++){
            if(A[end]==0){
                count--;
            }
            if(count < 0){
                len = max(len, end-start);
                while(A[start]==1) start++;
                if(A[start]==0){
                    start++;
                    count++;
                }
            }
        }
        len = max(len, end-start);
        return len==-1 ? A.size() : len;
    }
};

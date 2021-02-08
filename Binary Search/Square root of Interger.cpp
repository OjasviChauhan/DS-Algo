class Solution {
public:
    bool check(int n,int x){
        if(sqrt(x) < n) return true;
        return false;
    }
    
    int mySqrt(int x) {
        int l = 0, h = x;
        int res = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(check(mid,x)){
                h = mid-1;
            }
            else{
                res = mid;
                l = mid+1;
            }
        }
        return res;
    }
};

https://leetcode.com/contest/weekly-contest-238/problems/sum-of-digits-in-base-k/

class Solution {
public:
    int convert(int n, int k){
        string s = "";
        while(n > 0){
            s += to_string(n % k);
            n /= k;
        }
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    
    int sumBase(int n, int k) {
        int ans = 0, no;
        if(k != 10)
            no = convert(n,k);
        else
            no = n;
        while(no > 0){
            ans += no % 10;
            no = no / 10;
        }
        return ans;
    }
};

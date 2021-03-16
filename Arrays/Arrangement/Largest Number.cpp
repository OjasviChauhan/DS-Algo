// https://leetcode.com/problems/largest-number/

class Solution {
public:
    bool static cmp(string X,string Y){
        string XY = X.append(Y);
        string YX = Y.append(X);
        return XY > YX;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int i: nums){
            v.push_back(to_string(i));
        }
        sort(v.begin(),v.end(),cmp);
        string ans = "";
        
        for(string s : v){
            ans += s;
        }
        
        int i=0;
        if(ans[0] == '0')
        for(i=0; i<ans.size()-1; i++){
            if(ans[i+1] != '0')
                break;
        }
        
        return ans.substr(i);
    }
};

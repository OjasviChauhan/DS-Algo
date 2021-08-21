// https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() > num2.size()) swap(num1, num2);
        int n = num1.size();
        int m = num2.size();
        int t = n + m;
        vector<vector<int>> v(t, vector<int>(t, 0));
        int z = 1;
        
        for(int i = n-1; i >= 0; i--) {
            int c1 = num1[i] - '0';
            int carry = 0;
            int k = t-z;
        
            for(int j = m-1; j >= 0; j--) {
                int c2 = num2[j] - '0';
                int x = c1*c2 + carry;
                v[n-i-1][k--] = x % 10;
                carry = x / 10;
            }
            if(carry) v[n-i-1][k] = carry;
            z++;
        }
        
        string ans = "";
        int carry = 0;
        for(int j = t-1; j >= 0; j--) {
            int sum = carry;
            for(int i = 0; i < t; i++){
                sum += v[i][j];
            }
            char y = (sum % 10) + 48;
            carry = sum / 10;
            ans += y;
        }
        if(carry){
            char y = carry + 48;
            ans += y;
        }
        reverse(ans.begin(), ans.end());
        
        // removing extra prefix zeros from ans
        int i;
        for(i = 0; i < ans.size() - 1; i++){
            if(ans[i] != '0') break;
        }
        return ans.substr(i);
    }
};

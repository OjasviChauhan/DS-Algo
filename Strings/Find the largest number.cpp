// https://practice.geeksforgeeks.org/problems/find-the-largest-number4953/1#

/*
Given an integer N the task is to find the largest number which is smaller or 
equal to it and has its digits in non-decreasing order.
*/

class Solution{
public:
    int find(int n){
        string s = to_string(n);
        if (s.size() == 1) {
            return n;
        }
        int sz = s.size();
        int flag = -1;
        int i;
        for (i = sz - 2; i >= 0; i--) {
            if (s[i] > s[i + 1]) {
                int f = s[i] - '0';
                f--;
                char fc = f + 48;
                s[i] = fc;
                flag = i;
            }
        }
        if (i == -1 and flag == -1) {
            return n;
        }
    
        for (int i = flag + 1; i < sz; i++) {
            s[i] = '9';
        }
        int k;
        for (k = 0; k < s.size(); k++) {
            if (s[k] != '0') break;
        }
        string ss = s.substr(k);
        return stoi(ss);
    }
};

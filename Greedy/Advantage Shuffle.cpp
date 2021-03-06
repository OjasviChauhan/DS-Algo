// https://leetcode.com/problems/advantage-shuffle/

/*
For each B[i], we select the smallest number in A that is greater than B[i]. 
If there are no such number, we select the smalest number in A.
*/

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(begin(A), end(A));
        for (auto i = 0; i < B.size(); ++i) {
            auto p =  s.upper_bound(B[i]);
            if(p == s.end()) p = s.begin();
            A[i] = *p;
            s.erase(p);
        }
        return A;
    }
};

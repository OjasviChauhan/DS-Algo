// https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s; // use vector to simulate stack
        for (int i : a) {
            if(i > 0) s.push_back(i);
            else{
                while(!s.empty() && s.back() > 0 && s.back() < abs(i)) 
                    s.pop_back();
                if(s.empty() || s.back() < 0) s.push_back(i);
                else if(s.back() == -i) s.pop_back();
            }
        }
        return s;
    }
};

// https://leetcode.com/problems/min-stack/

Time: O(1)
Space: O(N)

class MinStack {
public:
    stack<int> s;
    stack<int> ss;
    
    void push(int val) {
        s.push(val);
        if(ss.size() == 0 or val <= ss.top()){
            ss.push(val);
        }
    }
    
    void pop() {
        if(s.top() == ss.top()) ss.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();
    }
};

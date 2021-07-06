// https://leetcode.com/problems/min-stack/


// Using two Stacks
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


// Using One Stack

class MinStack {
    stack<pair<int, int>> s;
public:
    void push(int x) {
        int ME;
        if (s.empty()) {
            ME = x;
        }
        else {
            ME = min(s.top().second, x);
        }
        s.push({x, ME});
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};

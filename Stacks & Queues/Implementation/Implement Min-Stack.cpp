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


// Using One Stack with Pairs
class MinStack {
    stack<pair<int, int>> s;
public:
    void push(int x) {
        int ME;
        if (s.empty()) ME = x;
        else ME = min(s.top().second, x);
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


//Using one stack and no pairs
stack<long> s;
long mini;
MinStack::MinStack() {
    while(!s.empty()) s.pop();
    mini = INT_MAX;
}

void MinStack::push(int x) {
    if(s.empty()) {
        s.push(x);
        mini = x;
    }
    else{
        if(x >= mini) s.push(x);
        else{
            s.push(2*x - mini);
            mini = x;
        }
    }
}

void MinStack::pop() {
    if(s.empty()) return;
    long x = s.top();
    s.pop();
    if(x < mini){
        mini = 2*mini - x;
    }
}

int MinStack::top() {
    if(s.empty()) return -1;
    long t = s.top();
    if(t < mini) return mini;
    return t;
}

int MinStack::getMin() {
    if(s.empty()) return -1;
    else return mini;
}

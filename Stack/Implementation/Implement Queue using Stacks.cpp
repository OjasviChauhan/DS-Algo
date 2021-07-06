// https://leetcode.com/problems/implement-queue-using-stacks/

// Time: O(N)
// Space: O(2N)

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int t = s1.top();
        s1.pop();
        return t;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

-----------------------------------------------------------------------

// Time: O(1) Avg , O(N) worst  AMORTIZED
// Space: O(2N)
    
class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:
    void push(int x) {
        input.push(x);
    }

    int pop() {
        if(!output.empty()){
            int t = output.top();
            output.pop();
            return t;
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int t = output.top();
            output.pop();
            return t;
        }
    }

    int peek() {
        if(!output.empty()) return output.top();
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }

    bool empty() {
        return input.empty() and output.empty();
    }
};

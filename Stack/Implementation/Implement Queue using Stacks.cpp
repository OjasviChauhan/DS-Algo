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

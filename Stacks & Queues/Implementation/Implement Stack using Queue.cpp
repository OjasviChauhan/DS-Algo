// https://leetcode.com/problems/implement-stack-using-queues/

// Using two Queues

class MyStack {
private:
    queue<int> *q1;
    queue<int> *q2;
public:
    MyStack() {
        q1 = new queue<int>;
        q2 = new queue<int>;
    }

    void push(int x) {
        q2->push(x);
        while(!q1->empty()){
            q2->push(q1->front());
            q1->pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int t = q1->front();
        q1->pop();
        return t;
    }

    int top() {
        return q1->front();
    }

    bool empty() {
        return q1->empty();
    }
};

--------------------------------------------------------------------------
    
// Using Single Queue
    
class MyStack {
private:
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int k = q.size()-1;
        while(k--){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

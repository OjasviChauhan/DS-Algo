#include<bits/stdc++.h>
using namespace std;

class MyStack {
private:
    int arr[1000];
    int top;
public:
    MyStack() {
        top = -1;
    }

    int pop() {
        if(top == -1) return -1;
        int ans = arr[top];
        top--;
        return ans;
    }

    void push(int x) {
        arr[++top] = x;   
    }
};

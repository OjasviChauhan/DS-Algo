// https://leetcode.com/problems/design-circular-queue/submissions/

class MyCircularQueue {
private:
    int *arr;
    int cnt;
    int front;
    int rear;
    int n;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        n = k;
        cnt = 0;
        rear = -1;
        front = 0;
    }
    
    bool enQueue(int value) {
        if(cnt == n) return false;
        rear++;
        arr[rear % n] = value;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(cnt == 0) return false;
        front++;
        cnt--;
        return true;
    }
    
    int Front() {
        if(cnt == 0) return -1;
        return arr[front % n];
    }
    
    int Rear() {
        if(cnt == 0) return -1;
        return arr[rear % n];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == n;
    }
};

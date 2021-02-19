// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:   
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
        }
        else if(num > maxHeap.top()){
            minHeap.push(num);
        }
        else{
            maxHeap.push(num);
        }
        
        // Balancing both Heaps
        if(maxHeap.size() - minHeap.size() == 2){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size() - maxHeap.size() == 2){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }  
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top())/2.0;
        }
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

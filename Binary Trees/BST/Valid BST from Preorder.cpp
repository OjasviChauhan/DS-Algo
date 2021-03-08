// https://www.interviewbit.com/problems/valid-bst-from-preorder/

int Solution::solve(vector<int> &pre) {
    stack<int> s;
    int n = pre.size();
    int root = INT_MIN; 

    for (int i=0; i<n; i++) { 
        // If we find a node who is on right side 
        // and smaller than root, return false 
        if (pre[i] < root) 
            return 0; 

        while (!s.empty() && pre[i] > s.top()) { 
            root = s.top(); 
            s.pop(); 
        } 
        // At this point either stack is empty or 
        // pre[i] is smaller than root, push pre[i] 
        s.push(pre[i]); 
    } 
    return 1; 
}

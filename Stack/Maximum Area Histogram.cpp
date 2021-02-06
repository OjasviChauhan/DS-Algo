vector<int> nextSmallerRight(vector<int> A,int n){
    vector<int> v;
    stack<pair<int,int>> s;
    
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            v.push_back(n);
        }
        else if(!s.empty() && A[i]>s.top().first){
            v.push_back(s.top().second);
        }
        else if(!s.empty() && A[i]<=s.top().first){
            while(!s.empty() && s.top().first>=A[i]){
                s.pop();
            }
            if(s.empty())
                v.push_back(n);
            else
                v.push_back(s.top().second);
        }
        s.push({A[i],i});
    }
    reverse(v.begin(),v.end());
    return v;
}

vector<int> nextSmallerLeft(vector<int> A,int n){
    vector<int> v;
    stack<pair<int,int>> s;
    
    for(int i=0;i<n;i++){
        if(s.empty()){
            v.push_back(-1);
        }
        else if(!s.empty() && A[i]>s.top().first){
            v.push_back(s.top().second);
        }
        else if(!s.empty() && A[i]<=s.top().first){
            while(!s.empty() && s.top().first>=A[i]){
                s.pop();
            }
            if(s.empty())
                v.push_back(-1);
            else
                v.push_back(s.top().second);
        }
        s.push({A[i],i});
    }
    return v;
}

int Solution::largestRectangleArea(vector<int> &A) {
    vector<int> r,l;
    int n = A.size();
    l = nextSmallerLeft(A,n);
    r = nextSmallerRight(A,n);
        
    int maxArea=0,area=0;
    for(int i=0;i<n;i++){
        area = A[i]*(r[i]-l[i]-1);
        if(area>maxArea)
            maxArea=area;
    }
    return maxArea;
}

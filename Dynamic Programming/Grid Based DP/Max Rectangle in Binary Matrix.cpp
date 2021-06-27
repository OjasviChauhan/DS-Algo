// https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

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

int MAH(vector<int> A){
    vector<int> l = nextSmallerLeft(A, A.size());
    vector<int> r = nextSmallerRight(A, A.size());
    
    int mx = 0, area = 0;
    for(int i=0;i<A.size();i++){
        area = (r[i] - l[i] - 1) * A[i];
        mx = max(mx, area);
    }
    return mx;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    vector<int> v(c);
    for(int j=0;j<c;j++){
        v[j] = A[0][j];
    }
    
    int ans = MAH(v);
    
    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
            if(A[i][j]){
                v[j] += A[i][j];
            }
            else v[j] = 0;
        }
        ans = max(ans, MAH(v));
    }
    return ans;
}

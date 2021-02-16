typedef pair<int, pair<int,int>> pi;

vector<int> Solution::solve(vector<vector<int> > &A) {
    priority_queue<pi, vector<pi>, greater<pi>> pq; 
    vector<int> v;
    int k = A.size();
    
    for(int i=0;i<k;i++){
        pq.push({A[i][0],{i,0}});
    }
    while(!pq.empty()){
        v.push_back(pq.top().first);
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();
        col++;
        if(col<A[row].size()){
            pq.push({A[row][col], {row,col}});
        }
    }
    return v;
}

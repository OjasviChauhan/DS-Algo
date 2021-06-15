// https://www.interviewbit.com/problems/snake-ladder-problem/

int bfs(int src, int des, vector<vector<int>> &adj){
    vector<int> dist(101, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    
    while(!q.empty()){
        int par = q.front();
        q.pop();
        
        for(int child : adj[par]){
            if(dist[child] == INT_MAX){
                q.push(child);
                dist[child] = dist[par] + 1;
            }
        }
    }
    return dist[des];
}

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<vector<int>> adj(101);
    
    int board[107] = {0};
    for(int i = 0; i < A.size(); i++){
        board[A[i][0]] = A[i][1] - A[i][0];
    }
    for(int i = 0; i < B.size(); i++){
        board[B[i][0]] = B[i][1] - B[i][0];
    }
    
    // connect possibilities of dices
    for(int i = 0; i <= 100; i++){
        for(int dice = 1; dice <= 6; dice++){
            int j = i + dice;
            j += board[j];
            if(j <= 100) adj[i].push_back(j);
        }
    }
    
    int ans = bfs(1,100,adj);
    return ans == INT_MAX ? -1 : ans;
}

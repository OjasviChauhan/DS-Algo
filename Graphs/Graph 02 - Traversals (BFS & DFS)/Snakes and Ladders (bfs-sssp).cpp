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



// https://leetcode.com/problems/snakes-and-ladders/

class Solution {
    unordered_map<int,list<int>> l;
public:
    void addEdge(int x,int y){
        l[x].push_back(y);
    }
    
    int bfs(int src,int dest){
        map<int,int> dist;
        queue<int> q;
        
        for(auto p:l){
            int node = p.first;
            dist[node] = INT_MAX;
        }
        
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            // traversing the nbrs of nodes present in queue
            for(auto nbr:l[node]){ 
                if(dist[nbr]==INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        return dist[dest];
    }
    
    int snakesAndLadders(vector<vector<int>>& input) {
        int row = input.size();
        int col = input[0].size();
        int size = row*col;
        
        int board[501] = {0};
        bool flag=true;
        int k = 1;
        
        for(int i=row-1;i>=0;i--){
            if(flag){
                for(int j=0;j<col;j++){
                    if(input[i][j]!=-1){
                        board[k] = input[i][j]-k;
                    }
                    k++;
                }
            }
            else{
                for(int j=col-1;j>=0;j--){
                    if(input[i][j]!=-1){
                        board[k] = input[i][j]-k;
                    }
                    k++;
                }
            }
            flag = !flag;
        }
        
        for(int i=0;i<=size;i++){
            for(int dice=1;dice<=6;dice++){
                int j = i + dice;
                j += board[j];
                
                if(j<=size){
                    addEdge(i,j);
                }
            }
        }
        addEdge(size,size);
        
        int ans = bfs(1,row*row);
        return ans==INT_MAX ? -1 : ans;
    }
};

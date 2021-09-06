// https://leetcode.com/problems/01-matrix/

class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& A) {
        int r = A.size();
        int c = A[0].size();
        
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(A[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = curr.first + dx[i];
                int ny = curr.second + dy[i];
                                
                if(nx < 0 or nx >= r or ny < 0 or ny >= c or A[nx][ny] == 0) 
                    continue;
                
                if(dist[nx][ny] > dist[curr.first][curr.second] + 1) {
                    dist[nx][ny] = dist[curr.first][curr.second] + 1;
                    q.push({nx,ny});
                }
            }
        }
        return dist;
    }
};

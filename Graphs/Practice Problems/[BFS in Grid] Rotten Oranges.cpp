// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1#

class Solution {
private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
public:
    bool isValid(int x, int y, int r, int c){
        return (x>=0 and x<r and y>=0 and y<c);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        
        int cntF = 0;
        vector<vector<int>> dist(r,vector<int>(c,-1));
        queue<pair<int,int>> q;
        
        for(int i=0; i<r; i++){
            for(int j=0; j < c; j++){
                if(grid[i][j] == 1) cntF++;
                else if(grid[i][j] == 2) {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            int x = node.first;
            int y = node.second;
           
            for(int i=0; i < 4; i++){
                int X = x + dx[i];
                int Y = y + dy[i];
                
                if(isValid(X,Y,r,c) and grid[X][Y] == 1 and dist[X][Y] == -1) { 
                    dist[X][Y] = dist[x][y] + 1;
                    grid[X][Y] = 2, cntF--;
                    q.push({X,Y});
                    ans = dist[X][Y];
                }
            }
        }
        return cntF ? -1 : ans;
    }
};

// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c, -1));
        
        // queue stores (x, y, dist, remaining k we can remove)
        queue<vector<int>> q;
        q.push({0,0,0,k});
        
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int x = t[0];
            int y = t[1];
            int dist = t[2];
            int rem_k = t[3];
            
            if(x < 0 or y < 0 or x >= r or y >= c) continue;
			
            if(x == r-1 and y == c-1) return dist;

            if(grid[x][y] == 1){
                if(rem_k > 0) // If we encounter an obstacle and we can remove it
                    rem_k--;
                else continue;  
            }
			
			// If the cell was previously visited and that time this cell had larger
            // k value than the current one, then we don't need to continue on this 
            // path because that previous path can go upto more eliminations.
            if(vis[x][y] != -1 and vis[x][y] >= rem_k)
                continue;
            
            vis[x][y] = t[3];
            
            for(int i = 0; i < 4; i++){
                int X = x + dx[i];
                int Y = y + dy[i];
                
                q.push({X, Y, dist + 1, rem_k});
            }
        }
        return -1;
    }
};

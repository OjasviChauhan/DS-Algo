// https://leetcode.com/problems/making-a-large-island/

class Solution {
public:
    int r, c;
    unordered_map<int,int> area;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(int i, int j, vector<vector<int>> &grid, int color) {
        if(i < 0 or i >= r or j < 0 or j >= c or grid[i][j] != 1) 
            return;
        
        grid[i][j] = color;
        area[color]++;
        
        for(int k = 0; k < 4; k++) {
            dfs(i + dx[k], j + dy[k], grid, color);
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        
        int ans = 0, color = 2; // initializing color with 2
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1){
                    dfs(i, j, grid, color);
                    ans = max(ans, area[color]);
                    color++; // changing to new color
                }
            }
        }
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> nbrs;
                    for(int k = 0; k < 4; k++) {
                        int nr = i + dx[k];
                        int nc = j + dy[k];
                        
                        if (nr < 0 or nr == r or nc < 0 or nc == c or grid[nr][nc] == 0) 
                            continue;
                        
                        nbrs.insert(grid[nr][nc]);
                    }
                    int candidateArea = 1;
                    for(int color : nbrs) candidateArea += area[color];
                    ans = max(ans, candidateArea);
                }
            }
        }
        return ans;
    }
};

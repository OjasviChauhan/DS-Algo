// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,int m,int n){
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0'){
            return;
        }
        // mark as visited ( 0: visited, 1: not visited)
        grid[i][j] = '0';
        dfs(i-1, j, grid,m,n);
        dfs(i+1, j, grid,m,n);
        dfs(i, j-1, grid,m,n);
        dfs(i, j+1, grid,m,n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        int cnt = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid,r,c);
                }
            }
        }   
        return cnt;
    }
};

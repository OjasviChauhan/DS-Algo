// https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:
    int n,m,empty=1,cnt=0;
    bool isSafe(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        if(i<n and j<m and i>=0 and j>=0 and !vis[i][j] and grid[i][j]!=-1){
            return true;
        }
        return false;
    }
    
    void dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        if(!isSafe(i,j,vis,grid))
            return;
        
        if(grid[i][j]==2){
            if(empty==0) cnt++;
            return;
        }
        
        vis[i][j] = true;
        empty--;
        
        dfs(i+1,j,vis,grid);
        dfs(i,j+1,vis,grid);
        dfs(i-1,j,vis,grid);
        dfs(i,j-1,vis,grid);

        vis[i][j] = false;
        empty++;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int si,sj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) empty++;
                else if(grid[i][j]==1){
                    si = i;
                    sj = j;
                }
            }
        }

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dfs(si,sj,vis,grid);
        return cnt;
    }
};

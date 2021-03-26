// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>& matrix,vector<vector<bool>>& vis,int height,int x,int y){
        if(x<0 or x>=n or y<0 or y>=m or vis[x][y] or matrix[x][y] < height)
            return;
        
        vis[x][y] = true;
        
        dfs(matrix,vis,matrix[x][y],x,y-1);
        dfs(matrix,vis,matrix[x][y],x,y+1);
        dfs(matrix,vis,matrix[x][y],x-1,y);
        dfs(matrix,vis,matrix[x][y],x+1,y);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return res;
        }
        n = matrix.size(), m = matrix[0].size();
        
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        
        // as there are multi starting points (all border points)
        // so we'll have to call dfs call from all those cells.
        for(int i=0; i<n; i++){
            dfs(matrix,pacific,INT_MIN,i,0);
            dfs(matrix,atlantic,INT_MIN,i,m-1);
        }
        for(int j=0; j<m; j++){
            dfs(matrix,pacific,INT_MIN,0,j);
            dfs(matrix,atlantic,INT_MIN,n-1,j);
        }
        
        for (int i=0; i<n; i++){ 
            for (int j=0; j<m; j++){ 
                if (pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;           
    }
};

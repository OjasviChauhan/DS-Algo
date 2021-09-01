// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(vector<vector<int>> &image, int x, int y, int oldColor, int newColor) {
        if(x < 0 or x >= image.size() or y < 0 or y >= image[0].size())
            return;
        
        if(image[x][y] == newColor or image[x][y] != oldColor) 
            return;
    
        image[x][y] = newColor;
        
        for(int i = 0; i < 4; i++){
            dfs(image, x + dx[i], y + dy[i], oldColor, newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int oldColor = image[sr][sc];
        dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
};

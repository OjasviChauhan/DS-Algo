// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

bool isSafe(int i,int j,int maze[][MAX],int n,bool vis[][MAX]){
    if(i>=0 and i<n and j>=0 and j<n and maze[i][j] == 1 and !vis[i][j]){
        return true;
    }
    return false;
}

void dfs(int i,int j,int maze[][MAX],int n,string &path,vector<string> &ans, bool vis[][MAX]){
    if(maze[i][j]==0)
        return;

    // If reach the last cell (n-1, n-1) then store the path and return
    if (i == n-1 && j == n-1) {
        ans.push_back(path);
        return;
    }

    // Mark the cell as visited
    vis[i][j] = true;

    // Check if downward move is valid
    if (isSafe(i+1, j, maze, n, vis)){
        path.push_back('D');
        dfs(i+1, j, maze, n, path, ans, vis);
        path.pop_back();
    }
    
    // Check if the left move is valid
    if (isSafe(i, j-1, maze, n, vis)){
        path.push_back('L');
        dfs(i, j-1, maze, n, path, ans, vis);
        path.pop_back();
    }

    // Check if the right move is valid
    if (isSafe(i, j+1, maze, n, vis)) {
        path.push_back('R');
        dfs(i, j+1, maze, n, path, ans, vis);
        path.pop_back();
    }

    // Check if the upper move is valid
    if (isSafe(i - 1, j, maze, n, vis)){
        path.push_back('U');
        dfs(i-1, j, maze, n, path, ans, vis);
        path.pop_back();
    }

    // Mark the cell as unvisited for other possible paths
    vis[i][j] = false;
}

vector<string> findPath(int maze[MAX][MAX], int n) {
    vector<string> ans;
    string path;
    bool vis[n][MAX];
    memset(vis, false, sizeof(vis));

    dfs(0,0,maze,n,path,ans,vis);
    
    sort(ans.begin(),ans.end());
    return ans;
}

#include <bits/stdc++.h>
#define MAX 5
using namespace std;

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

    // Now check for all 4 neigbours
    // going down
    if (isSafe(i+1, j, maze, n, vis)){
        path.push_back('D');
        dfs(i+1, j, maze, n, path, ans, vis);
        path.pop_back();
    }

    // going left
    if (isSafe(i, j-1, maze, n, vis)){
        path.push_back('L');
        dfs(i, j-1, maze, n, path, ans, vis);
        path.pop_back();
    }

    // going right
    if (isSafe(i, j+1, maze, n, vis)) {
        path.push_back('R');
        dfs(i, j+1, maze, n, path, ans, vis);
        path.pop_back();
    }

    // going up
    if (isSafe(i - 1, j, maze, n, vis)){
        path.push_back('U');
        dfs(i-1, j, maze, n, path, ans, vis);
        path.pop_back();
    }

    // Mark the cell as unvisited for other possible paths
    vis[i][j] = false;
}

// Function to store and print all the valid paths 
void solve(int maze[MAX][MAX], int n){
    vector<string> ans;
    string path;
    bool vis[n][MAX];
    memset(vis, false, sizeof(vis));

    dfs(0,0,maze,n,path,ans,vis);

    // Print all possible paths
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << endl;
}

// Driver code
int main()
{
    int maze[MAX][MAX] = {{1, 0, 0, 0},
                         { 1, 1, 0, 1},
                         { 1, 1, 0, 0},
                         { 0, 1, 1, 1,}};
    int n = 4;
    solve(maze, n);

    return 0;
}

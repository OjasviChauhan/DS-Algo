// https://www.interviewbit.com/problems/region-in-binarymatrix/

int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};

bool isSafe(int i,int j,int r,int c){
    return (i>=0 and i<r and j>=0 and j<c);
}

void dfs(int i,int j,vector<vector<int>> &A, int r,int c,int &cnt){
    A[i][j] = 0;
    cnt++;
    
    for(int k = 0; k < 8; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(isSafe(x,y,r,c) and A[x][y] == 1){
            dfs(x, y, A, r, c, cnt);
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    int ans = 0;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int cnt = 0;
            if(A[i][j] == 1){
                dfs(i,j,A,r,c,cnt);
                ans = max(ans, cnt);
            }
        }
    }
    return ans;
} 

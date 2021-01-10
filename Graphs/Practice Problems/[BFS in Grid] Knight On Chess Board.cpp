// https://www.interviewbit.com/problems/knight-on-chess-board/

bool isValid(int i,int j,int m,int n){
    if(i>=1 && i<=m && j>=1 && j<=n){
        return true;
    }
    return false;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int dx[8]={-2,-1,1,2,-2,-1,2,1};
    int dy[8]={-1,-2,-2,-1,1,2,1,2};
    
    bool visited[A+1][B+1];
    for(int i=0;i<=A;i++){
        for(int j=0;j<=B;j++){
            visited[i][j]=false;
        }
    }
    visited[C][D]=true;
    
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{C,D}});
    
    int X,Y;
    
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int count = p.first;
        int x = p.second.first;
        int y = p.second.second;
        
        if(x==E and y==F) return count;
        
        for(int i=0;i<8;i++){
            X = x + dx[i];
            Y = y + dy[i];
            if(isValid(X,Y,A,B) and !visited[X][Y]){
                visited[X][Y] = true;
                q.push({count+1,{X,Y}});
            }
        }
    }
    return -1;
}

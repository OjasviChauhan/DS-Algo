// https://www.interviewbit.com/problems/valid-path/

bool isInside(int circle_x,int circle_y,int rad,int x,int y) { 
    if ((x-circle_x)*(x-circle_x)+(y-circle_y)*(y-circle_y)-rad*rad <= 0) 
        return true; 
    return false; 
}
bool isValid(int i,int j,int m,int n){
    if(i>=0 && i<=m && j>=0 && j<=n){
        return true;
    }
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    int dx[8]={-1,1,0,0,-1,-1,1,1};
    int dy[8]={0,0,-1,1,-1,1,-1,1};
    
    bool visited[A+1][B+1];
    for(int i=0;i<=A;i++){
        for(int j=0;j<=B;j++){
            visited[i][j]=false;
            for(int k=0;k<C;k++){
                if(isInside(E[k],F[k],D,i,j)){
                    visited[i][j] = true;
                    break;
                }
            }
        }
    }
    visited[0][0]=true;
    
    queue<pair<int,int>> q;
    q.push({0,0});
    
    int X,Y;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x==A and y==B) return "YES"; 
        
        for(int i=0;i<8;i++){
            X = x + dx[i];
            Y = y + dy[i];
            if(isValid(X,Y,A,B) and !visited[X][Y]){
                visited[X][Y]=true;
                q.push({X,Y});
            }
        }
    }
    return "NO";
}

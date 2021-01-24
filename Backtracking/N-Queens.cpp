class Solution {
public:
    bool isSafe(int board[][10],int i,int j,int n){
        // checking in above rows at same column;
        for(int row=0;row<i;row++){
            if(board[row][j]==1){
                return false;
            }
        }
        
        int x = i;
        int y = j;
        
        // checking for left upper diagonal
        while(x>=0 and y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        
        x = i;
        y = j;
        
        // checking for right upper diagonal
        while(x>=0 and y<=n){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    
    bool solve(int board[][10],int i,int n,vector<vector<string>> &ans){
        if(i==n){
            // we have successfully placed all queens in n rows (0...n-1)
            // print the board
            vector<string> S;
            for(int i=0;i<n;i++){
                string s="";
                for(int j=0;j<n;j++){
                    if(board[i][j]==1){
                        s += "Q";
                    }
                    else s += ".";
                }
                S.push_back(s);
            }
            ans.push_back(S);
            
            // returning false will not stop code after first configuration
            // it will revert back and search for all possible configuration.
            return false;
        }
        
        // try to place the queen in current row and call on the remaining part
        for(int j=0;j<n;j++){
            // I've to check whether the i,j th position is safe to place the queen or not
            if(isSafe(board,i,j,n)){
                // place the queen - assuming i,j is the right position
                board[i][j] = 1;
                
                if(solve(board,i+1,n,ans))
                    return true;
                
                // if we reached here, means i,j is not right position
                // and our assumption is wrong so we'll remove queen from there 
                board[i][j] = 0;  //backtrack
            }
        }
        
        // we have tried all positions and couldn't place the queen anywhere. 
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        int board[10][10]={0};
        vector<vector<string>> ans;
        solve(board,0,n,ans);
        return ans;
    }
};

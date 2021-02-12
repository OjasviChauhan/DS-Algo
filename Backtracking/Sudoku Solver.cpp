// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool canPlace(vector<vector<char>>& board,int i,int j,int n,char number){
        // row and col check
        for(int x=0;x<n;x++){
            if(board[i][x]==number or board[x][j]==number){
                return false;
            }
        }
        
        // sub-grid check
        int rn = sqrt(n);
        int sx = (i/rn)*rn;
        int sy = (j/rn)*rn;
        
        for(int x=sx;x<sx+rn;x++){
            for(int y=sy;y<sy+rn;y++){
                if(board[x][y] == number){
                    return false;
                }
            }
        }
    
        return true;
    }
    
    bool solve(vector<vector<char>>& board,int i,int j,int n){
        // Base Cases
        if(i==n){
            return true;
        }
        if(j==n){
            return solve(board,i+1,0,n);
        }
        if(board[i][j] != '.'){
            return solve(board,i,j+1,n);
        }
        
        // Main Recursive Case
        for(int number=1;number<=9;number++){
            char c = number + 48;
            if(canPlace(board,i,j,n,c)){
                board[i][j] = number + 48;
            
                if(solve(board,i,j+1,n)){
                    return true;
                }
            }
        }
        // Backtrack
        board[i][j] = '.';
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(board,0,0,n);
    }
};

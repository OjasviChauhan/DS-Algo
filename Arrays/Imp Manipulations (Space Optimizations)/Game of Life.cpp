// https://leetcode.com/problems/game-of-life/

class Solution {
public:
    bool isValid(int i,int j,int r,int c){
        if(i<r and i>=0 and j<c and j>=0)
            return true;
        return false;
    }
    
    void gameOfLife(vector<vector<int>>& A) {
        int r = A.size();
        int c = A[0].size();
        
        int dx[8] = {-1,1,0,0,-1,1,-1,1};
        int dy[8] = {0,0,1,-1,-1,-1,1,1};
        
        for(int row=0; row < r; row++){
            for(int col=0; col < c; col++){
                // if cell is live
                if(A[row][col] == 1 or A[row][col] == -1){
                    int nbr = 0;
                    // calculating nbrs...
                    for(int k=0; k < 8; k++){
                        int i = row + dx[k];
                        int j = col + dy[k];
                        if(isValid(i,j,r,c)){
                            if(A[i][j] == 1 or A[i][j] == -1)
                                nbr++;
                        }
                    }
                    if(nbr < 2 or nbr > 3){
                        A[row][col] = -1;
                    }
                    
                }
                // if cell is dead
                else if(A[row][col] == 0 or A[row][col] == 2){
                    int nbr = 0;
                    // calculating nbrs...
                    for(int k=0; k < 8; k++){
                        int i = row + dx[k];
                        int j = col + dy[k];
                        if(isValid(i,j,r,c)){
                            if(A[i][j] == 1 or A[i][j] == -1)
                                nbr++;
                        }
                    } 
                    if(nbr == 3){
                        A[row][col] = 2;
                    }
                }
            }
        }
        
        for(int row=0; row < r; row++){
            for(int col=0; col < c; col++){
                if(A[row][col] == -1){
                    A[row][col] = 0;
                }
                else if(A[row][col] == 2){
                    A[row][col] = 1;
                }
            }
        }
    }
};

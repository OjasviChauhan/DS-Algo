// https://leetcode.com/problems/queens-that-can-attack-the-king/

/*

Trace in all directions from the king until you hit a queen or go off the board. 
Since the board is limited to 8 x 8, we can use a boolean matrix to lookup queen 
positions; we could use a hash map for a larger board.

*/

class Solution {
public: 
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k){
        bool grid[8][8] = {};
        for (auto& q : queens) grid[q[0]][q[1]] = true;
        
        vector<vector<int>> res;
        
        // travelling in all 8 directions. These two nested loops will
        // run 9 times in which we'll skip one i.e. when i == j == 0.
        for (auto i = -1; i <= 1; ++i) {
            for (auto j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue; // here we'll end up on the same position
                
                // new king's position
                int x = k[0] + i; 
                int y = k[1] + j;
                
                // now keep going in this direction until we found any queen or 
                // we go out of bound.
                while (min(x, y) >= 0 && max(x, y) < 8) {
                    if (grid[x][y]) {
                        res.push_back({ x, y });
                        break;
                    }
                    x += i, y += j;
                }
            }
        }
        return res;
    }
};

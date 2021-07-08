// https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++){
            if(gas[i] < cost[i]) continue;
            else{
                int tank = 0;
                for(int j = i; j < i + n; j++) {
                    tank += gas[j % n] - cost[j % n];
                    if(tank < 0){
                        i = j;
                        break;
                    }
                }
                if(tank >= 0) return i;
            }
        }
        return -1;
    }
};

// https://leetcode.com/problems/maximum-average-pass-ratio/

typedef pair<int,int> pii;

struct cmp{
    bool operator()(pii a, pii b){
        double ad = (a.first+1)/(double)(a.second+1) - (a.first)/(double)a.second;
        double bd = (b.first+1)/(double)(b.second+1) - (b.first)/(double)b.second;
        return ad < bd;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& A, int k) {
        double ans;
        priority_queue<pii, vector<pii>, cmp> pq;
        for(vector<int> i: A)
            pq.push({i[0],i[1]});
        
        // do the pushing of k extra students
        while(k--){
            pii cur = pq.top(); 
            pq.pop();
            cur.first++, cur.second++;
            pq.push(cur);
        }
        
        while(!pq.empty()){
            pii cur = pq.top(); 
            pq.pop();
            ans += cur.first / (double) cur.second;
            if(pq.empty()) {
                ans /= A.size();
                break;
            }
        }
        return ans;
    }
};

/*
Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)
*/

typedef pair<int, pair<int,int>> pi;
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<pi> pq;
    set<pair<int,int>> S;
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    pq.push({ A[n-1]+B[n-1], {n-1, n-1} });
    S.insert({n-1,n-1});

    vector<int> ans;
    int k=n;
    while(k--){
        pi top = pq.top();
        pq.pop();
        ans.push_back(top.first);
        int L = top.second.first;
        int R = top.second.second;
        
        if( R>0 && L>=0  && S.find({L,R-1}) == S.end() ){
            pq.push({ A[L]+B[R-1], {L,R-1} });
            S.insert({L,R-1});
        }
        if( R>=0 && L>0 && S.find({L-1,R})== S.end() ){
            pq.push({A[L-1]+B[R], {L-1,R}});
            S.insert({L-1, R});
        }
    }
    return ans;
}

// Time: O(NlogN)
// Space: O(N)

// https://www.interviewbit.com/problems/n-max-pair-combinations/

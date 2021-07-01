// https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    int xr = 0, count = 0;
    unordered_map<int,int> m;
    for(int i=0;i<A.size();i++) {
        xr ^= A[i];
        if(xr == B) count++;
        if(m.find(xr ^ B) != m.end()){
            count += m[xr ^ B];
        }
        m[xr]++;
        cout << count << " ";
    }
    return count;
}

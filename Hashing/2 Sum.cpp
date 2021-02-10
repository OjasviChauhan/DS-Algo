// https://www.interviewbit.com/problems/2-sum/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    // map to store the mapping from number to its index. 
    unordered_map<int, int> M;
    vector<int> ans;

    for (int i = 0; i < A.size(); i++){
        int required = B - A[i];
        if (M.find(required) != M.end()){
            // We have our solution. index1 = M[required], index2 = i + 1 ( 1 based ). 
            ans.push_back(M[required]);
            ans.push_back(i + 1);
            return ans;
        }
        if (M.find(A[i]) == M.end()){
            // We want to maintain the minimum index at M[A[i]]. i + 1 will 
            // obviously be greater than whats already present.
            M[A[i]] = i + 1;
        }
    }
    return ans;
}

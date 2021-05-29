// https://www.interviewbit.com/problems/2-sum/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> mp;
    vector<int> ans;
    
    for(int i=0;i<A.size();i++){
        if(mp.find(B - A[i]) != mp.end()){
            ans.push_back(mp[B-A[i]]);
            ans.push_back(i+1);
            return ans;
        }
        else{
            mp.insert({A[i],i+1});
        }
    }
    return ans;
}

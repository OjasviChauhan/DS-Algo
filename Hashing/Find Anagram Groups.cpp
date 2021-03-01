// https://www.interviewbit.com/problems/anagrams/

// Anagrams will map to the same string if the characters in the string are sorted.
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> ans;
    unordered_map<string,vector<int>> mp;
    for(int i=0;i<A.size();i++){
        string s = A[i];
        sort(s.begin(),s.end());
        mp[s].push_back(i+1);
    }
    
    for(auto p : mp){
        ans.push_back(p.second);
    }
    return ans;
}

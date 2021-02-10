https://www.interviewbit.com/problems/check-palindrome/

int Solution::solve(string A) {
    if(A.size()==1) return 1;
    unordered_map<char,int> mp;
    for(char c : A){
        mp[c]++;
    }
    //for(auto p:mp) cout<<p.first<<"->"<<p.second<<endl;
    int cnt1=0;
    if(A.size()%2==0){
        for(auto p:mp){
            if(p.second%2 != 0){
                return 0;
            }
        }
    }
    else{
        for(auto p:mp){
            if(p.second%2 != 0) cnt1++;
            if(cnt1 > 1) return 0;
        }
    }
    return 1;
}

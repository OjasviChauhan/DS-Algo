// https://www.interviewbit.com/problems/check-palindrome/

// A set of characters can form a palindrome if at most one character occurs 
// odd number of times and all characters occur even number of times.

int Solution::solve(string A) {
    int cnt[26] = {0};
    for(char &c : A){
        cnt[c-'a']++;
    }
    int odd = 0;
    for(int i=0;i<26;i++){
        if(cnt[i] & 1) odd++;
        if(odd > 1) return 0;
    }
    return 1;
}

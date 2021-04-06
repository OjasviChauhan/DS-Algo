// https://www.hackerrank.com/challenges/twins/problem

#include<bits/stdc++.h>
using namespace std;

const int N = 100000;

vector<int> primes;
vector<int> p(N+1,1);

void sieve(){
    for(int i=2;i<=N;i++){
        if(p[i]){
            primes.push_back(i);
            for(int j=i; j<=N; j+=i){
                p[j] = 0; // not prime
            }
        }
    }
}

int solve(int n,int m){
    bool segment[m-n+1];
    for(int i=0; i < m-n+1; i++){
        segment[i] = 1;
    }
    
    for(int i : primes){
        if(i*i > m) break;
        
        int start = (n/i)*i;
        if(i >= n and i <= m){
            start = 2*i;
        }
        
        for(int j = start; j <= m; j += i){
            segment[j-n] = 0;
        }
    }
    vector<int> segPrimes;
    for(int i=n; i<=m; i++){
        if(segment[i-n])
            segPrimes.push_back(i);
    }

    int cnt = 0;
    for(int i = 0; i < segPrimes.size()-1; i++){
        if(abs(segPrimes[i+1] - segPrimes[i]) == 2)
            cnt++;
    }
    return cnt;
}

int main(){
    sieve();
    
    int n,m;
    cin>>n>>m;
    
    cout << solve(n,m) << '\n';
    
    return 0;
}

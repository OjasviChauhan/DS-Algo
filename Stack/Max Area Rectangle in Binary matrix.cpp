#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
  public:
    vector<int> nextSmallerLeft(int A[], int n){
        vector<int> res;
        stack<pair<int,int>> s;
        
        for(int i=0;i<n;i++){
            if(s.empty()){
                res.push_back(-1);
            }
            else if(!s.empty() and A[i] > s.top().first){
                res.push_back(s.top().second);
            }
            else if(!s.empty() and A[i] <= s.top().first){
                while(!s.empty() and A[i] <= s.top().first){
                    s.pop();
                }
                if(s.empty())
                    res.push_back(-1);
                else
                    res.push_back(s.top().second);
            }
            s.push({A[i], i});
        }
        return res;
    }
    
    vector<int> nextSmallerRight(int A[], int n){
        vector<int> res;
        stack<pair<int,int>> s;
        
        for(int i = n - 1; i >= 0; i--){
            if(s.empty()){
                res.push_back(n);
            }
            else if(A[i] > s.top().first){
                res.push_back(s.top().second);
            }
            else if(A[i] <= s.top().first){
                while(!s.empty() and A[i] <= s.top().first){
                    s.pop();
                }
                if(s.empty())
                    res.push_back(n);
                else
                    res.push_back(s.top().second);
            }
            s.push({A[i], i});
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    int MAH(int A[],int n){
        vector<int> l = nextSmallerLeft(A, n);
        vector<int> r = nextSmallerRight(A, n);

        int mx = 0, area = 0;
        for(int i=0; i < n; i++){
            int area = A[i]*(r[i]-l[i]-1);
            mx = max(mx, area);
        }
        return mx;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        int v[m];
        for(int j = 0; j < m; j++){
            v[j] = M[0][j];
        }
        int ans = MAH(v,m);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(M[i][j])
                    v[j] += M[i][j];
                else
                    v[j] = 0;
            }
            ans = max(ans, MAH(v,m));
        }
        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

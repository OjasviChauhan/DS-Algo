// https://codeforces.com/contest/1536/problem/B

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string s1="a";
    for(int i=1;i<=26;i++){
        if(s.find(s1)==string::npos){
            cout<<s1<<"\n";return;
        }
        s1[0]++;
    }
    s1="aa";
    for(int i=1;i<=26;i++){
        for(int j=1;j<=26;j++){
            if(s.find(s1)==string::npos){
                cout<<s1<<"\n";return;
            }
            s1[1]++;
        }
        s1[0]++;
        s1[1]='a';
    }
 
 
    s1="aaa";
    for(int i=1;i<=26;i++){
        for(int j=1;j<=26;j++){
            for(int k=1;k<=26;k++){
                if(s.find(s1)==string::npos){
                    cout<<s1<<"\n";return;
                }
                s1[2]++;
            }
            s1[1]++;
            s1[2]='a';
        }
        s1[0]++;
        s1[1]=s1[2]='a';
    }
}

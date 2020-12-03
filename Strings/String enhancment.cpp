/*
There is a compressed string eg. ”ab2c3”, the string has lowercase characters and numbers. We can uncompress the given 
string as follows: whenever we get a number “n” in the string, the portion of the string before the number will repeat 
“n” times. So in the above example, we get a 2, so the string will become “ababc3”, now we get a 3, so the final string
will be “ababcababcababc”. 
Given a compressed string and a number k, you have to output the kth character in the 
uncompressed string. 1 <= length of string <= 1500 1 <= n <= 1000 1 <= k < 231

Example:
input: ab2c3 10 
output: c
*/



#include <iostream>
using namespace std;

string add(string s,int n){
    string temp="";
    for(int i=0;i<n;i++){
        temp += s;
    }
    return temp;
}


int main() {
    string s;
    cin>>s;
    int k;
    cin>>k;

    string res="";
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            int n = (int)s[i] - 48;
            res += add(res,n-1);
        }
        else res+=s[i];
    }
    cout<<res<<endl;
    for(int i=0;i<res.size();i++){
        if(i==k-1){
            cout<<res[i]<<endl;;
            break;
        }
    }
}

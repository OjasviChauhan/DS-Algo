/*

Write a program that reads a word and determine how many words, 
with the same number of letters as the input, it might represent.

Input: ETA
Output: 7

Explanation
------------

ETA can be represented as . – . –
ETA — > .–.–

ETET — > .–.–
AET — > .–.–
ENA — > .–.–
EK –> .–.–
AA — > .–.–
RT — > .–.–

*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define int long long
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<endl;
int mod = 1000000007;

unordered_map<string, string> dp;
string str;

string convert(string s, vector<string> morseCode) {
    string req = "";
    for (int i = 0; i < s.size(); i++) {
        int idx = s[i] - 'A';
        req += morseCode[idx];
    }
    return req;
}

void helper(string &ds, string req, vector<string> morseCode, vector<string> &ans) {
    if (dp.count(ds) != 0) str = dp[ds];
    else str = convert(ds, morseCode), dp[ds] = str;

    if (str.size() > req.size()) return;

    if (str == req) {
        ans.push_back(ds);
        return;
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        ds.push_back(c);
        helper(ds, req, morseCode, ans);
        ds.pop_back();
    }
}

int solve(string s, vector<string> morseCode) {
    vector<string> ans;
    string req = convert(s, morseCode);
    string ds = "";
    helper(ds, req, morseCode, ans);

    print(ans);

    return ans.size();
}

int32_t main() {
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    vector<string> morseCode
    = {
        ".-", "-...", "-.-.",
        "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-",
        ".-..", "--", "-.", "---",
        ".--.", "--.-", ".-.", "...",
        "-", "..-", "...-", ".--",
        "-..-", "-.--", "--.."
    };

    string s = "ETA";
    cout << solve(s, morseCode);

#ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(7) << fixed;
    cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif

    return 0;
}

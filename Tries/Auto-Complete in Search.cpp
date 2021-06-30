#include <bits/stdc++.h>
using namespace std;
#define limit 3

class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool terminal;

    TrieNode(char d) {
        data = d;
        terminal = false;
    }
};

void insert(string word, TrieNode* root) {
    TrieNode* temp = root;
    for (char c : word) {
        if (temp->children[c]) {
            temp = temp->children[c];
        }
        else {
            TrieNode* new_node = new TrieNode(c);
            temp->children[c] = new_node;
            temp = new_node;
        }
    }
    temp->terminal = true;
}

bool isLeaf(TrieNode* root) {
    for (int i = 0; i < 26; i++) {
        char c = i + 97;
        if (root->children[c])
            return false;
    }
    return true;
}

void suggestionRec(TrieNode* temp, string &ds, vector<string> &v) {
    if (temp->terminal) {
        v.push_back(ds);
    }
    if (v.size() == limit) return;
    if (isLeaf(temp)) return;

    for (int i = 0; i < 26; i++) {
        char c = i + 97;
        if (temp->children[c]) {
            ds.push_back(c);
            suggestionRec(temp->children[c], ds, v);
            ds.pop_back();
        }
    }
}

vector<string> getSuggestions(string preQuery, TrieNode* root) {
    vector<string> v;
    TrieNode* temp = root;

    for (char &c : preQuery) {
        if (temp->children[c]) {
            temp = temp->children[c];
        }
    }
    //if (temp->terminal) v.push_back(preQuery);
    if (isLeaf(temp)) return v;
    else {
        string ds = preQuery;
        suggestionRec(temp, ds, v);
    }
    return v;
}

vector<vector<string>> solve(vector<string> repository, string query) {
    vector<vector<string>> res;
    TrieNode* root = new TrieNode('0');

    for (string &word : repository) {
        insert(word, root);
    }

    string temp = "";
    for (char &c : query) {
        temp.push_back(c);
        if (temp.size() >= 2) {
            vector<string> ans = getSuggestions(temp, root);
            res.push_back(ans);
        }
    }
    return res;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<string> repository(n);
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        repository[i] = word;
    }

    string query;
    cin >> query;

    vector<vector<string>> res = solve(repository, query);

    for (vector<string> v : res) {
        for (string s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}

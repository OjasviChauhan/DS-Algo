// https://leetcode.com/problems/short-encoding-of-words/

class Node{
    public:
        char data;
        unordered_map<char,Node*> children;
    
        Node(char d){
            data = d;
        }
};

class Trie{
public:
    
    Node* root;
    
    Trie(){
        root = new Node('/0');
    }
    
    void insert(string s){
        Node* temp = root;
        for(char ch : s){
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            }
            else{
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
    }
    
    void depth(Node* root,int d,vector<int> &ans){
        if(root->children.size()==0){
            ans.push_back(d);
            return;
        }
        for(auto p : root->children){
            depth(p.second,d+1,ans);
        }
    }
    
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie t;
        for(int i=0; i<words.size(); i++){
            reverse(words[i].begin(),words[i].end());
            t.insert(words[i]);
        }
        vector<int> ans;
        t.depth(t.root,0,ans);
        int res = 0;
        for(int i : ans){
            res += i+1;
        }
        return res;
    }
};


// Another Approach (Faster than Trie)

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0;
        int n = words.size();
        for (auto i = 0; i < n; ++i){ 
            reverse(words[i].begin(), words[i].end());
        }
        sort(words.begin(),words.end());
        
        for(int i=0; i < n-1; i++){
            if(words[i] == words[i+1].substr(0,words[i].size())){
                res += 0;
            }
            else{
                res += words[i].size() + 1;
            }
        }
        return res + words[n-1].size() + 1;
    }
};

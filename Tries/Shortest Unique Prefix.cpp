// https://www.interviewbit.com/old/problems/shortest-unique-prefix/

class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> children;
    int freq;

    TrieNode(char d) {
        data = d;
        freq = 0;
    }
};

void insert(TrieNode* root, string str) {
    TrieNode* temp = root;
    for (char c : str) {
        if (temp->children[c]) {
            temp = temp->children[c];
            temp->freq++;
        }
        else {
            TrieNode* new_node = new TrieNode(c);
            temp->children[c] = new_node;
            temp = new_node;
            temp->freq++;
        }
    }
}

void solve(TrieNode* root, int i, string s, string &ds, vector<string> &ans) {
    if (root == NULL) return;
    if (root->freq == 1) {
        ans.push_back(ds);
        return;
    }
    if(i == s.size()) return;
    
    char c = s[i];
    if (root->children[c]) {
        ds.push_back(c);
        solve(root->children[c], i+1, s, ds, ans);
        ds.pop_back();
    }
}

vector<string> Solution::prefix(vector<string> &A) {
    TrieNode* root = new TrieNode('R');
    for(int i=0; i < A.size(); i++){
        insert(root, A[i]);
    }

    vector<string> ans;
    for(string s : A){
        string ds = "";
        solve(root, 0, s, ds, ans);
    }
    
    return ans;
}

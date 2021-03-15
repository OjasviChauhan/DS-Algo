// https://leetcode.com/problems/implement-trie-prefix-tree/

class Node {
public:
    char data;
    unordered_map<char,Node*> children;
    bool terminal;
    
    Node(char d){
        data = d;
        terminal = false;
    }
};

class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node('/0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* temp = root;
        for(char ch : word){
            if(temp->children.count(ch))
                temp = temp->children[ch];
            else{
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp = root;
        for(char ch : word){
            if(temp->children.count(ch) == 0)
                return false;
            else
                temp = temp->children[ch];  
        }
        return temp->terminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char ch : prefix){
            if(temp->children.count(ch) == 0)
                return false;
            else
                temp = temp->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#

class Solution{
    public:
    bool ispar(string x){
        stack<char> s;
        for(char &c : x){
            if(c == '[' or c=='{' or c=='(') s.push(c);
            else if(c == ']'){
                if(!s.empty() and s.top() == '[') 
                    s.pop();
                else return false;
            }
            else if(c == '}'){
                if(!s.empty() and s.top() == '{') 
                    s.pop();
                else return false;
            }
            else if(c == ')'){
                if(!s.empty() and s.top() == '(') 
                    s.pop();
                else return false;
            }
        }
        if(s.size()) return false;
        return true;
    }
};

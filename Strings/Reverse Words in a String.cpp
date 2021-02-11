// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string A) {
        vector<string> s;
        string str = "";

        // removing extra spaces from the end
        int i = A.size()-1;
        while(A[i--]==' ') A.pop_back();

        for(int i=0;i<A.size();i++){
            if(isalpha(A[i]) or isdigit(A[i])){
                str.push_back(A[i]);
            }
            else{
                s.push_back(str);
                s.push_back(" ");
                str.clear();
                while(A[i]==' ') i++;   // skipping extra spaces coming in between
                i--;
            }
        }
        s.push_back(str);
        if(s.empty())
            return A;
        
        string res = "";
        while(!s.empty()){
            string str = s.back();
            for(auto c : str){
                if(isalpha(c) or isdigit(c))
                    res += c;
                else 
                    res += ' ';
            }
            s.pop_back();
        }

        i = res.size()-1;
        while(res[i--] == ' ') res.pop_back();

        return res;
    }
};

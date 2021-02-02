// https://leetcode.com/problems/find-the-closest-palindrome/

class Solution {
public:
    bool allDigitisNine(string n){
        for(char c:n){
            if(c!='9') 
                return false;
        }
        return true;
    }
    
    bool check1(string n){
        if(n[0] != '1') return false;
        for(int i=1;i<n.size();i++){
            if(n[i] != '0') return false;
        }
        return true;
    }
    
    bool check2(string n){
        if(n[0] != '1') return false;
        if(n[n.size()-1] != '1') return false;
        for(int i=1;i<n.size()-1;i++){
            if(n[i] != '0') return false;
        }
        return true;
    }
    
    bool isPalindrome(string n){
        string s = n;
        reverse(s.begin(),s.end());
        if(s==n) return true;
        return false;
    }
    
    string nearestPalindromic(string n) {
        int len = n.size();
        long N = stol(n);
        
        if(N <= 10 or check1(n)){
            N -= 1;
            return to_string(N);
        }
        
        else if(N==11 or check2(n)){
            N -= 2;
            return to_string(N);
        }
        
        else if(allDigitisNine(n)){
            N += 2;
            return to_string(N);
        }
        
        else if(isPalindrome(n)){
            if(len%2!=0){
                string root = n.substr(0,len/2+1);
                string rev = n.substr(0,len/2);
                reverse(rev.begin(),rev.end());
                long root_int = stol(root);
                string c1 = to_string(root_int-1) + rev;
                string c2 = to_string(root_int+1) + rev;
                return (abs(N-stol(c1)) <= abs(N-stol(c2)) && isPalindrome(c1)) ? c1 : c2;
            }   
            else{
                string root = n.substr(0,len/2);
                long root_int = stol(root);
                
                string s1 = to_string(root_int-1);
                string rev1 = s1;
                reverse(rev1.begin(),rev1.end());
                string c1 = s1 + rev1;
                
                string s2 = to_string(root_int+1);
                string rev2 = s2;
                reverse(rev2.begin(),rev2.end());
                string c2 = s2 + rev2;
                
                return (abs(N-stol(c1)) <= abs(N-stol(c2))) ? c1 : c2;
            }
        }
        else{
            if(len%2!=0){
                string root = n.substr(0,len/2+1);
                string rev = n.substr(0,len/2);
                reverse(rev.begin(),rev.end());
                long root_int = stol(root);
                string c1 = to_string(root_int) + rev;
                string c2 = to_string(root_int+1) + rev;
                string c3 = to_string(root_int-1) + rev;
                string C;
                if(abs(N-stol(c2)) < abs(N-stol(c3))){
                    C = c2;
                } else C = c3;
                
                return (abs(N-stol(c1)) <= abs(N-stol(C))) ? c1 : C;
            }   
            else{
                string root = n.substr(0,len/2);
                string rev1 = root;
                reverse(rev1.begin(),rev1.end());
                string c1 = root + rev1;
                
                long root_int = stol(root);
                string s2 = to_string(root_int+1);
                string rev2 = s2;
                reverse(rev2.begin(),rev2.end());
                string c2 = s2 + rev2;
                
                string s3 = to_string(root_int-1);
                string rev3 = s3;
                reverse(rev3.begin(),rev3.end());
                string c3 = s3 + rev3;
                
                string C;
                if(abs(N-stol(c2)) <= abs(N-stol(c3))){
                    C = c2;
                } else C = c3;
                
                int d1 = abs(N-stol(C));
                int d2 = abs(N-stol(c1));
                if (d1 < d2){
                    return C;
                }
                else if(d1 == d2){
                    return (stoi(C) < stoi(c1)) ? C : c1;
                }
                else return c1;
            }
        }
        return "-1";
    }
};


// EDGE CASES

// AllDigitisNine: 999 --> 1001  (+2)
// Check1: 10, 100, 1000 --> 9, 99, 999 (-1)
// Check2: 11, 101, 1001, 10001, --> 9, 99, 999 (-2)

// if n is palindrome
    // if n is odd
        // 12321 --> 124+21 , 122+21
        // 12921 --> 130+31 , 128+21       
        // 12021 --> 119+11 , 121+21

    // if n is even
        // 1221 --> 11+11 , 13+31
        // 1991 --> 20+02 , 18+81

// if not palindrome
    // if n is odd
        // 12345 --> 123+21 , 124+21 , 122+21  
        // 12045 --> 120+21 , 121+21 , 119+11
    
    // if n is even
        // 1294 --> 12+21 , 13+31 , 11+11
        // 1999 --> 19+91 , 20+02 , 18+81
        // 1002 --> 10+01 , 11+11 , 

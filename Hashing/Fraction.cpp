// https://www.interviewbit.com/problems/fraction/

string Solution::fractionToDecimal(int numerator, int denominator) {
    if(numerator == 0) return "0";
    int64_t n = numerator, d = denominator;
    string res = "";

    // if any one of the number is -ve and other is +ve
    if((n < 0) ^ (d < 0)) res += '-';

    n = abs(n), d = abs(d);
    res += to_string(n/d);
    int64_t rem = n % d; 

    if(rem == 0) return res;
    res += '.';

    unordered_map<int,int> mp;
    while(rem){
        if(mp.find(rem) != mp.end()){
            res.insert(mp[rem], "(");
            res.push_back(')');
            break;
        }
        mp[rem] = res.size();
        rem *= 10;
        res += to_string(rem/d);
        rem %= d;
    }
    return res;
}

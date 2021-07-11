bool is9(string &str, int pos) {
    if (pos < 0 or pos >= str.size() or str[pos] != '9') return false;
    else return true;
}
 
string Solution::solve(string A) {
    string bkp = A;
    int l = 0, r = A.size() - 1;
    while (l <= r) {
        if (A[l] != A[r]) {
            A[r] = A[l];
        }
        l++, r--;
    }
 
    if (A > bkp) return A;
 
    l--, r++;
 
    while (is9(A, l)) {
        A[l] = '0';
        A[r] = '0';
        l--, r++;
    }
    
    if (l >= 0) { // if L is >= 0 then R is < str.size() always
        A[l] += 1;
        A[r] = A[l];
    } else { // we enter here if our number is full of 9s. e.g. "99999"
        A[0] = '1';
        A += '1';
    }
    return A;
}

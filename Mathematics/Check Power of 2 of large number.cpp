// https://www.interviewbit.com/problems/power-of-2/

int divide(string A, int n){
    if (n == 1 and A[A.size() - 1] == '1')
        return 1;
    if ((A[A.size() - 1] - '0') % 2 != 0)
        return 0;

    string s = "", ans = "";
    for (int i = 0; i < A.size(); i++) {
        s += A[i];
        int num = stoi(s);
        if (num < 2) {
            if (i == 0) {
                i++;
                s += A[i];
                num = stoi(s);
            }
        }
        int k = (num / 2);
        int res = 2 * k;
        ans.push_back(k + '0');
        int rem = num - res;
        s.clear();
        if (rem != 0) {
            s += (rem + '0');
        }
    }
    return divide(ans, ans.size());
}

int Solution::power(string A) {
    int n = A.size();
    if(n == 1 and A[0] == '1') return 0;
    return divide(A,n);
}

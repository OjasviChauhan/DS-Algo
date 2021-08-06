// https://www.interviewbit.com/old/problems/painters-partition-problem/

bool check(vector<long> &time, int k, long mid) {
    long painters = 1, t = 0;
    for(int i = 0; i < time.size(); i++) {
        t += time[i];
        if(t > mid){
            painters++;
            t = time[i];
        }
        if(painters > k) return false;
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int n = C.size();
    long lo = INT_MIN;
    long hi = 0;

    vector<long> time(n);

    for(int i = 0; i < n; i++) {
        time[i] = (long)C[i] * (long)B;
        lo = max(lo, time[i]);
        hi += time[i];
    }

    long ans = -1;
    while(lo <= hi) {
        long mid = hi - (hi-lo) / 2;
        if(check(time, A, mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return ans % 10000003;
}

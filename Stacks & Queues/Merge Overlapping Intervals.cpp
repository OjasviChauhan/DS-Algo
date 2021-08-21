/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compare(Interval a,Interval b){
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), compare);
    vector<Interval> ans;
    ans.push_back(A[0]);

    for(int i = 1; i < A.size(); i++){
        Interval top = ans.back();
        if(top.end < A[i].start) {
            ans.push_back(A[i]);
        }
        else if(top.end < A[i].end) {
            top.end = A[i].end;
            ans.pop_back();
            ans.push_back(top);
        }
    }
    return ans;
}

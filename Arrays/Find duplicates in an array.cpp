// https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1#

vector<int> duplicates(int a[], int n) {
    vector<int> v;
    for(int i=0;i<n;i++){
        int index = a[i]%n;
        a[index] += n;
    }
    for(int i=0;i<n;i++){
        if(a[i]/n > 1){
            v.push_back(i);
        }
    }
    if(v.empty()) return {-1};
    return v;
}

// O(N) Time
// O(1) Space

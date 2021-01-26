// https://leetcode.com/problems/maximum-gap/

// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//Try to solve it in linear time/space.

/*

Now, first try to think if you were already given the minimum value MIN and maximum value MAX in the array of size N, 
under what circumstances would the max gap be minimum and maximum ?

Obviously, maximum gap will be maximum when all elements are either MIN or MAX making maxgap = MAX - MIN.

Maximum gap will be minimum when all the elements are equally spaced apart between MIN and MAX. Lets say the spacing between them is gap.

So, they are arranged as

        MIN, MIN + gap, MIN + 2*gap, MIN + 3*gap, ... MIN + (N-1)*gap 
where
        MIN + (N-1)*gap = MAX 
     => gap = (MAX - MIN) / (N - 1). 
     
So, we know now that our answer will lie in the range [gap, MAX - MIN].
Now, if we know the answer is more than gap, what we do is create buckets of size gap for ranges

        [MIN, MIN + gap), [Min + gap, `MIN` + 2* gap) ... and so on
        
There will only be (N-1) such buckets. We place the numbers in these buckets based on their value.

If you pick any 2 numbers from a single bucket, their difference will be less than gap, and hence they would 
never contribute to maxgap ( Remember maxgap >= gap ). We only need to store the largest number and the smallest
number in each bucket, and we only look at the numbers across bucket.

Now, we just need to go through the bucket sequentially ( they are already sorted by value ), and get the difference
of min_value with max_value of previous bucket with at least one value. We take maximum of all such values.

*/



int Solution::maximumGap(const vector<int> &arr) {
    int n = arr.size();
    if(n < 2) return 0;
    // Find maximum and minimum in arr[]
    int maxVal = arr[0], minVal = arr[0];
    for (int i = 1; i < n; i++) {
            maxVal = max(maxVal, arr[i]);
            minVal = min(minVal, arr[i]);
    }

    // Arrays to store maximum and minimum values
    // in n-1 buckets of differences.
    int maxBucket[n - 1];
    int minBucket[n - 1];
    fill_n(maxBucket, n - 1, INT_MIN);
    fill_n(minBucket, n - 1, INT_MAX);

    // Expected gap for every bucket.
    float delta = (float)(maxVal - minVal) / (float)(n - 1);

    // Traversing through array elements and
    // filling in appropriate bucket if bucket
    // is empty. Else updating bucket values.
    for (int i = 0; i < n; i++) {
        if (arr[i] == maxVal || arr[i] == minVal)
            continue;

        // Finding index of bucket.
        int index = (float)(floor(arr[i] - minVal) / delta);
        maxBucket[index] = max(maxBucket[index], arr[i]);
        minBucket[index] = min(minBucket[index], arr[i]);
    }

    // Finding maximum difference between maximum value
    // of previous bucket minus minimum of current bucket.
    int prev_val = minVal;
    int max_gap = 0;
    for (int i = 0; i < n - 1; i++) {
        if (minBucket[i] == INT_MAX)
            continue;
        max_gap = max(max_gap, minBucket[i] - prev_val);
        prev_val = maxBucket[i];
    }
    max_gap = max(max_gap, maxVal - prev_val);

    return max_gap;
}

/*
If anyone is confused why the count was increased by myMap[ curr - k ] instead of just count+=1 . 
It was because prefix sum can be same because of some negative values in the array. so out next
occuring k will also pair  with those negative values also . 


consider this case A : [3 4  7    2   -3   1   4   2   1 ]  
                       preSum : [3 7 14 16 13 14 18 20 21]


you can see 14 occured twice  because of the subsequence [2 -3 1] their sum is 0. so When you are
at the final index with value 1 . you have curr - k = 21 - 7 = 14 . you check for 14 it has occured
twice . so you need to consider subsequences [2 -3 1 4 2 1] and [4 2 1] . Hope this helps
*/

#include <bits/stdc++.h>
using namespace std;
 
// Function to find number of subarrays
// with sum exactly equal to k.
int findSubarraySum(int arr[], int n, int sum)
{
    // STL map to store number of subarrays
    // starting from index zero having
    // particular value of sum.
    unordered_map<int, int> prevSum;
 
    int res = 0;
 
    // Sum of elements so far.
    int currsum = 0;
 
    for (int i = 0; i < n; i++) {
 
        // Add current element to sum so far.
        currsum += arr[i];
 
        // If currsum is equal to desired sum,
        // then a new subarray is found. So
        // increase count of subarrays.
        if (currsum == sum)
            res++;
 
        // currsum exceeds given sum by currsum
        //  - sum. Find number of subarrays having
        // this sum and exclude those subarrays
        // from currsum by increasing count by
        // same amount.
        if (prevSum.find(currsum - sum) != prevSum.end())
            res += (prevSum[currsum - sum]);
 
        // Add currsum value to count of
        // different values of sum.
        prevSum[currsum]++;
    }
 
    return res;
}
 
int main()
{
    int arr[] = { 10, 2, -2, -20, 10 };
    int sum = -10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findSubarraySum(arr, n, sum);
    return 0;
}

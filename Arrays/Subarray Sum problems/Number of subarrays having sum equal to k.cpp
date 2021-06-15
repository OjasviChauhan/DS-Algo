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
		// - sum. Find number of subarrays having
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
	int arr[] = {1,2,3,0,0,3};
	int sum = 3;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findSubarraySum(arr, n, sum);
	return 0;
}

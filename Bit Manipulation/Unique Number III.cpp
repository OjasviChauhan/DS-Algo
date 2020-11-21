// https://hack.codingblocks.com/app/practice/5/433/problem

/*
We are given an array containg n numbers. All the numbers are 
present thrice except for one number which is only present once. 
Find the unique number. Only use - bitwise operators, and no extra space.
*/


#include<iostream>
using namespace std;

int main() {
	// making an array of constant size to store bits of numbers
	// it can maximum be the size of 64 bit integer.
	int count[64] = {0};

	int n,no;
	cin>>n;
	for(int i=0;i<64;i++){
		cin>>no;
		// update the count array by extracting bits and incrementing 
		// the count of each bit.
		int j=0;
		while(no>0){
			int last_bit = (no&1);
			count[j] += last_bit;
			j++;
			no = no>>1;
		}
	}

	// iterate over the array and firstly reducing all counts by the factor
	// of 3 and then converting 0s and 1s into a number. That number will be
	// our final answer.
	int p = 1;
	int ans = 0;
	for(int i=0;i<64;i++){
		count[i] %= 3;
		ans += count[i] * p;
		p = p<<1;
	}
	cout<<ans<<endl;
	return 0;
}


// time: O(1)
// space: O(1)

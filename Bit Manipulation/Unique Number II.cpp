// https://hack.codingblocks.com/app/practice/5/213/problem


/*
We are given an array containg n numbers. All the numbers are present twice except for two numbers 
which are present only once. Find the unique numbers in linear time without using any extra space.
*/
 

#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;

	int A[n];
	int res = 0;
	for(int i=0;i<n;i++){
		cin>>A[i];
		res ^= A[i];  // filtering the XOR product of two 
	}  	              // unique numbers and storing it in res.
		
	
	// finding position of first set-bit of resulted ans
	int temp = res;
	int pos=0;
	while((temp&1) != 1){
		pos++;
		temp = temp>>1;
	}

	int x=0, y=0;
  
	// Now filtering those numbers who have their first set-bit
	// at same position which resulted ans had and then taking
	// XOR with each other in order to find out the first unique number.
	int mask = (1<<pos);
	for(int i=0;i<n;i++){
		if((A[i] & mask) > 0){
			x ^= A[i];
		}
	}

	// taking XOR of first number with resulted ans
	// will give us the second unique number.
	y = res ^ x;    
	cout<<min(x,y)<<" "<<max(x,y)<<endl;

	return 0;
}

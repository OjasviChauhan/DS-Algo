// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    
    // calculating a^b pair of aur ans by taking xor of all 
    // elements of array and then with all numbers from 1 to n.
    int x = 0;
    for(int i=0;i<n;i++){
        x ^= A[i];
    }
    for(int i=1;i<=n;i++){
        x ^= i;
    }
    
    // finding position of right most setbit
    int temp = x;
    int pos=0;
    while((temp&1) != 1){
        pos++;
        temp = temp>>1;
    }
    
    // dividing those numbers into 2 different buckets a and b.
    int a=0,b=0;
    int mask = 1<<pos;
    
    // firstly seperating them into different buckets by taking XOR
    // of all array elements on the condition that which elements have
    // setbit at "pos" position.
    for(int i=0;i<n;i++){
        if(A[i]&mask)
            a ^= A[i];
        else
            b ^= A[i];
    }
    
    // then doing XOR with all numbers from 1 to n to cancel out
    // all same elements and remaining just missing and repeated 
    // number in two different variables i.e, a and b
    for(int i=1;i<=n;i++){
        if(i&mask)
            a ^= i;
        else
            b ^= i;
    }
    
    // distinguishing which number should be repeated and which should 
    // be missing among these two a and b.
    for(auto num: A){
        if(num==a)
            return {a, b};
    }
    return {b, a};
}

// time: O(5n)
// space: O(1)

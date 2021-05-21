// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int lo = 0;
        int hi = n-1;
        int i = 0;
        while(i <= r){
            if(a[i] == 0){
                swap(a[lo++], a[i++]);
            }
            else if(a[i] == 2){
                swap(a[i], a[hi--]);
            }
            else i++;
        }
    }
};

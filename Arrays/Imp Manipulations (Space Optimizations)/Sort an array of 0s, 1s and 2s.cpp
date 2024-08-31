// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

/*
This problem is the same as the famous “Dutch National Flag problem”.

    "Given N balls of colour red, white or blue arranged in a line in random order. 
    You have to arrange all the balls such that the balls with the same colours are 
    adjacent with the order of the balls, with the order of the colours being red, 
    white and blue (i.e., all red coloured balls come first then the white coloured
    balls and then the blue coloured balls)."

    arr[0] to arr[lo – 1]: This part will have all the 0s.
    arr[lo] to arr[mid – 1]: This part will have all the 1s.
    arr[mid] to arr[hi]: This will be our unsorted array.
    arr[hi + 1] to arr[N – 1]: This part will have all the 2s.
*/

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

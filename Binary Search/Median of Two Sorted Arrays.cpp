// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            swap(nums1,nums2);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n1==0 and n2==0) return 0;
        else if(n1==0 and n2==1) return nums2[0];
        else if(n2==0 and n1==1) return nums1[0];
        
        int lo = 0; int hi = n1;
        while(lo <= hi){
            int cut1 = lo + (hi-lo)/2;
            int cut2 = (n1+n2)/2 - cut1;
            
            int l1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            int r1 = cut1==n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2==n2 ? INT_MAX : nums2[cut2];
            
            if(l1 > r2){
                hi = cut1-1;
            }
            else if(l2 > r1){
                lo = cut1+1;
            }
            else{
                return (n1+n2)%2==0 ? (max(l1,l2)+min(r1,r2))/(double)2 : min(r1,r2);
            }
        }
        return 0;
    }
};

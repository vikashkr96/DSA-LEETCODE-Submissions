class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

      if (nums1.size() >nums2.size()){
        return findMedianSortedArrays(nums2,nums1); // nums1 should be smaller 
      } 

      int n1= nums1.size();
      int n2 = nums2.size();
      int total = n1+n2;
      int half = (total+1)/2;
      int left = 0, right = n1;

      while(left <= right){
        int i = left + (right-left)/2; // cut in nums1
        int j = half-i;                // cut in nums2

        int Aleft, Aright, Bleft, Bright;

        if (i>0)Aleft = nums1[i-1];
        else Aleft = INT_MIN;
        
        if (i < n1) Aright = nums1[i];
        else Aright = INT_MAX;

        if (j > 0) Bleft = nums2[j - 1];
        else Bleft = INT_MIN;

        if (j < n2) Bright = nums2[j];
        else Bright = INT_MAX;

        // Check correct partition
        if (Aleft <= Bright && Bleft <= Aright) {

                // Odd length
            if (total % 2 == 1)
                return max(Aleft, Bleft);

                // Even length
            return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
        }
        else if (Aleft > Bright) {
            right = i - 1;
        }
        else {
            left = i + 1;
        }
    }

    return 0.0;  // Should never reach
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;  // to handle cases when k >= n

        reverseArray( nums, 0, n-1 );
        reverseArray( nums, 0, k-1 );
        reverseArray( nums, k, n-1 );
        
    }

    void reverseArray(vector<int>& nums, int st, int end){
        while(st < end){
            int temp = nums[st];
            nums[st] = nums[end];
            nums[end] = temp;
            st++;
            end--;
        }
    }
};





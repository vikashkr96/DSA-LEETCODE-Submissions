class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maximum = INT_MIN;
        int pref = 1, suff = 1;
        int n = arr.size();

        for(int i = 0; i<n ; i++){
            if(pref == 0) pref = 1;
            if(suff ==0 ) suff = 1;

            pref *= arr[i];
            suff *= arr[n-1-i];

            maximum = max(maximum , max(pref , suff));
        }
        return maximum;
    }
};
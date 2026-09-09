class Solution {
public:

    void findCombo(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        // base case
        if(idx == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        // picking up 
        if(arr[idx] <= target){
            ds.push_back(arr[idx]);
            findCombo(idx, target-arr[idx], arr, ans, ds);
            // backtrack
            ds.pop_back();
        }

        // not picking up
        findCombo(idx+1, target, arr, ans, ds);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds;
        findCombo(0,target, candidates, ans, ds);
        return ans;
    }
};
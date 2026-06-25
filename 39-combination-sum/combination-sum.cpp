class Solution {
public:

    void solve(vector<int>& candidates, int target, int index,
               vector<int>& curr, vector<vector<int>>& ans) {

        // base case
        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        if(index == candidates.size() || target < 0)
            return;


        // picking current element 
        curr.push_back(candidates[index]);

        solve(candidates, target - candidates[index], index, curr, ans);

        // backtrack
        curr.pop_back();


        // skipping current element
        solve(candidates, target, index + 1, curr, ans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, target, 0, curr, ans);

        return ans;
    }
};
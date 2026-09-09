class Solution {
public:
    void backtrack(int index, int target, vector<int>& candidates,
                   vector<int>& current, vector<vector<int>>& result) {

        // Base case
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicate elements at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no need to continue
            if (candidates[i] > target)
                break;

            // Choosing
            current.push_back(candidates[i]);

            // Moving to i + 1 because each element can be used only once
            backtrack(i + 1, target - candidates[i],
                      candidates, current, result);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, target, candidates, current, result);

        return result;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m-1;

        while(i < n && j >=0){
            int cell = matrix[i][j];
            if(cell == target){
                return true;
            }else if(cell < target){
                i++;
            }else{
                j--;
            }
        }
        return false;
        
    }
};
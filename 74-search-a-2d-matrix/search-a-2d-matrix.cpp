class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int st = 0, end = n*m-1;
        while(st <= end){
            int mid = st + (end-st)/2;
            int row = mid/m, col = mid % m;

            if (matrix[row][col] == target) return true;
            if(matrix[row][col] < target ) {
                st = mid +1;
            }else{
                end = mid -1;
            }

        }
        return false;
        
    }
};
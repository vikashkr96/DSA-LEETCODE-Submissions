class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int n = matrix.size();
        int m = matrix[0].size();

        int srow = 0, scol = 0;
        int erow = n - 1, ecol = m - 1;

        while(srow <= erow && scol <= ecol){

            // top
            for(int j = scol; j <= ecol; j++)
                ans.push_back(matrix[srow][j]);

            // right
            for(int i = srow + 1; i <= erow; i++)
                ans.push_back(matrix[i][ecol]);

            // down
            if(srow == erow)
                break;

            for(int j = ecol - 1; j >= scol; j--)
                ans.push_back(matrix[erow][j]);

            // left
            if(scol == ecol)
                break;

            for(int i = erow - 1; i >= srow + 1; i--)
                ans.push_back(matrix[i][scol]);

            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};
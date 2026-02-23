class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));

        int srow = 0, scol = 0;
        int erow = n-1, ecol = n-1;
        int num = 1;

        while(srow <= erow && scol <= ecol){


            for(int j = scol; j <= ecol; j++)
                mat[srow][j] = num++;
            srow++;

    
            for(int i = srow; i <= erow; i++)
                mat[i][ecol] = num++;
            ecol--;

            if(srow <= erow){
                for(int j = ecol; j >= scol; j--)
                    mat[erow][j] = num++;
                erow--;
            }

            if(scol <= ecol){
                for(int i = erow; i >= srow; i--)
                    mat[i][scol] = num++;
                scol++;
            }
        }
        return mat;
    }
};
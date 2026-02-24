class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        int col0 = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               if(arr[i][j] == 0){
                // marking i-th row
                arr[i][0] = 0;
                // marking j-th col
                if(j != 0){
                    arr[0][j] = 0;
                }else{
                    col0 = 0;
                }

               } 
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(arr[i][j] != 0){
                    if(arr[i][0] == 0 || arr[0][j] == 0){
                        arr[i][j] = 0;
                    }
                }
            }
        }
        if(arr[0][0] == 0){
            for(int j = 0; j <m; j++){
                arr[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i = 0; i < n; i++){
                arr[i][0] = 0;
            }
        }
    }
};


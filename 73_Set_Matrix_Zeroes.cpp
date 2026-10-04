class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        bool updateCol = false, updateRow = false;
        for(int i = 0; i < m; i ++){
            if(matrix[i][0] == 0){
                updateCol = true;
                break;
            }
        }

        for(int j = 0; j < n; j ++){
            if(matrix[0][j] == 0){
                updateRow = true;
                break;
            }
        }

        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i ++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < n; j ++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < n; j ++){
            if(matrix[0][j] == 0){
                for(int i = 0; i < m; i ++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(updateCol){
            for(int i = 1; i < m; i ++) matrix[i][0] = 0;
        }
        if(updateRow){
            for(int j = 1; j < n; j ++) matrix[0][j] = 0;
        }
    }
};
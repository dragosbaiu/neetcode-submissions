class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        int l = 0;
        int r = row*column - 1;

        while (l <= r){
            int m = l + (r-l)/2;
            if (target < matrix[m/column][m%column]){
                r = m-1;
            }
            else if (target > matrix[m/column][m%column]){
                l = m + 1;
            }
            else {
                return true;
            }
        } 
        return false;
    }
};

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size(), m = mat[0].size();
    int row = 0, col = m - 1;
    while(row < n && col >= 0){
        if(mat[row][col] == target){
            return 1;
        }else if(mat[row][col] < target){
            row += 1;
        }else{
            col -= 1;
        }
    }
    return 0;
}
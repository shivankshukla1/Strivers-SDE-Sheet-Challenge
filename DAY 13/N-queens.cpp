void func(int ind, vector<int>& curr, vector<vector<int>>& answer, vector<int>& row, vector<int>& upper, vector<int>& lower){
    if(ind == row.size()){
        answer.push_back(curr);
        return;
    }
    int n = row.size();
    for(int i = 0; i < row.size(); i ++){
        int target = ind*n + i;
        if(row[i] == 0 && lower[i+ind] == 0 && upper[n - 1 - i + ind] == 0){
            row[i] = 1;
            lower[i + ind] = 1;
            upper[n - 1 - i + ind] = 1;
            curr[target] = 1;
            func(ind + 1, curr, answer, row, upper, lower);
            curr[target] = 0;
            row[i] = 0;
            lower[i + ind] = 0;
            upper[n - 1 - i + ind] = 0;
            
        }
    }
}


vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> answer;
    vector<int> curr(n*n, 0);
    vector<int> row(n, 0);
    vector<int> upper_dia(2*n - 1, 0), lower_dia(2*n - 1, 0); 
    func(0, curr, answer, row, upper_dia, lower_dia);


    return answer;
}
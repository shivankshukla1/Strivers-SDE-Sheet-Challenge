#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j++){
            int left = dp[i-1][j];
            int right = dp[i][j-1];
            int mini = 0;
            if(min(left, right) == 1e9){
                mini = 0;
            }else{
                mini = min(left, right);
            }

            dp[i][j] = mini + grid[i-1][j-1];
        }
    }
    return dp[n][m];
}
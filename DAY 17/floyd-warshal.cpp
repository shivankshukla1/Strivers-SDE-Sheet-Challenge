int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    for(int i =0 ; i < n; i ++){
        dp[i][i] = 0;
    }   
    src -= 1;
    dest -= 1;
    for(auto i : edges){
        int u = i[0] - 1, v = i[1] - 1, w = i[2];
        dp[u][v] = w;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] > (dp[i][k] + dp[k][j])
                    && (dp[k][j] != 1e9
                        && dp[i][k] != 1e9))
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    return dp[src][dest];
}
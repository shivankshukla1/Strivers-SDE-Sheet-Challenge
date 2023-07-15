#include <bits/stdc++.h>


long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n + 1, vector<long>(value + 1, 0));
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= value; j++){
            if(denominations[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i][j-denominations[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][value];
}
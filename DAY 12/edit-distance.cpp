#include <bits/stdc++.h>
int editDistance(string a, string b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= m; j ++){
            if(i == 0 || j == 0){
                dp[i][j] = i + j;
            }else{
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                }
            }
        }
    }
    return dp[n][m];
}
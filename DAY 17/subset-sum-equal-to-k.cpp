#include <bits/stdc++.h> 

bool func(int ind, vector<int>& arr, int k, vector<vector<int>> &dp){
    if(k == 0){
        return 1;
    }
    if(ind == arr.size()){
        return 0;
    }
    if(dp[ind][k] != -1){
        return dp[ind][k];
    }
    int answer = func(ind + 1, arr, k, dp);
    if(k >= arr[ind]){
        answer += func(ind + 1, arr, k - arr[ind], dp);
    }
    

    return dp[ind][k] = answer;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return func(0, arr, k, dp);
}
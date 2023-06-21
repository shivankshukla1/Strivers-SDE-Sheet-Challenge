#include <bits/stdc++.h> 

bool ispalin(string& s){
    int l = 0, r = s.size() - 1;
    while(l <= r){
        if(s[l] != s[r]){
            return 0;
        }
        l += 1;
        r -= 1;
    }
    return 1;
}


int func(int ind, string& s, vector<int> &dp){
    if(ind == s.size()){
        return -1;
    }
    if(dp[ind] != -2){
        return dp[ind];
    }
    int answer = INT_MAX;
    string now = "";
    for(int i = ind; i < s.size(); i ++){
        now += s[i];
        if(ispalin(now)){
            answer = min(answer, func(i + 1, s, dp) + 1);
        }
    }
    return dp[ind] = answer;
}


int palindromePartitioning(string str) {
    vector<int> dp(str.size() + 1, -2);
    return func(0, str, dp);
}

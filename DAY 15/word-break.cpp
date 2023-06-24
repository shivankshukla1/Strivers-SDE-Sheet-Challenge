#include <bits/stdc++.h> 

bool func(int ind, string& s, unordered_map<string, int> &m, vector<int> &dp){
    if(ind == s.size()){
        return 1;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }
    bool answer = 0;

    string now = "";
    for(int i = ind; i < s.size(); i++){
        now += s[i];
        if(m.find(now) != m.end()){
            answer |= func(i + 1, s, m, dp);
        }
    }


    return dp[ind] = answer;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_map<string, int> m;
    for(auto i : arr){
        m[i] += 1;
    }
    vector<int> dp(target.size() + 1, -1);
    return func(0, target, m, dp);
}
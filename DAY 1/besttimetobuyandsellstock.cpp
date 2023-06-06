#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mini = INT_MAX;
    int answer = 0;
    for(auto i : prices){
        mini = min(mini, i);
        answer = max(answer, i - mini);
    }
    return answer;
}
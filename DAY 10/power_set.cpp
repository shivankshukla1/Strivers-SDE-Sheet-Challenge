#include <bits/stdc++.h>

void func(int ind, vector<int>& v, vector<int>& curr, vector<vector<int>>& answer){
    if(ind == v.size()){
        answer.push_back(curr);
        return;
    }
    func(ind + 1, v, curr, answer);
    curr.push_back(v[ind]);
    func(ind + 1, v, curr, answer);
    curr.pop_back();
}

vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> answer;
    vector<int> curr;
    func(0, v, curr, answer);
    return answer;
}
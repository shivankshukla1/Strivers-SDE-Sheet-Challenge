#include <bits/stdc++.h>

void func(int ind, vector<int>& num, int& curr, vector<int>& answer){
    if(ind == num.size()){
        answer.push_back(curr);
        return;
    }
    func(ind + 1, num, curr, answer);
    curr += num[ind];
    func(ind + 1, num, curr, answer);
    curr -= num[ind];
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> answer;
    int curr = 0;
    func(0, num, curr, answer);
    sort(answer.begin(), answer.end());
    return answer;
}
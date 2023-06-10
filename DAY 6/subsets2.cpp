#include <bits/stdc++.h> 


void func(int ind, vector<int>& arr, vector<int>& curr, vector<vector<int>>& answer){
    if(ind == arr.size()){
        answer.push_back(curr);
        return;
    }
    curr.push_back(arr[ind]);
    func(ind+1, arr, curr, answer);
    curr.pop_back();

    while(ind < arr.size() -1 && arr[ind] == arr[ind+1]){
        ind += 1;
    }
    func(ind + 1, arr, curr, answer);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> answer;
    vector<int> curr;
    sort(arr.begin(), arr.end());
    func(0, arr, curr, answer);

    sort(answer.begin(), answer.end());
    return answer;
}
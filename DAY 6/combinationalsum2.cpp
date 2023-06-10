#include <bits/stdc++.h>
void func(int ind, vector<int>& arr, int  target, vector<int>& curr, vector<vector<int>>& answer){
	if(ind == arr.size()){
		if(target == 0){
			answer.push_back(curr);
		}
		return;
	}
	curr.push_back(arr[ind]);
	func(ind + 1, arr, target - arr[ind], curr, answer);
	curr.pop_back();

	while(ind + 1 < arr.size() && arr[ind] == arr[ind+1]){
		ind += 1;
	}
	func(ind+1, arr, target, curr, answer);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(), arr.end());
	vector<vector<int>> answer;
	vector<int> curr;

	func(0, arr, target, curr, answer);

	return answer;
}

#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int answer = INT_MIN;
	int mini = 1, maxi = 1;
	for(auto i : arr){
		if(i < 0){
			swap(maxi, mini);
		}
		
			mini = min(i, mini*i);
			maxi = max(i, maxi*i);
			answer = max(answer, maxi);
	}
	return answer;
}

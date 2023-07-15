#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	int answer = INT_MIN;
	vector<int> sum(n, 0);
	vector<int> len(n, 1);
	for(int i =0 ; i < rack.size(); i++){
		sum[i] = rack[i];
		answer = max(answer, sum[i]);
	}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < i; j++){
			if(rack[j] < rack[i]){
				if(len[i] <= len[j] + 1){
					len[i] = len[j] + 1;
					sum[i] = max(sum[i], sum[j] + rack[i]);
					answer = max(answer, sum[i]);
				}
			}
		}
	}
	return answer;
}
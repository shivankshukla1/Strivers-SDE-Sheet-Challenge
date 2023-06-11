#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> answer;
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n - 2; i ++){
		if(i == 0 || arr[i] != arr[i-1]){
			int j = i + 1, k = n - 1;
			while(j < k){
				int now = arr[i] + arr[j] + arr[k];
				if(now == K){
					answer.push_back({arr[i], arr[j], arr[k]});
					while(j + 1 < k && arr[j] == arr[j+1]){
						j += 1;
					}
					while(j < k - 1 && arr[k] == arr[k-1]){
						k -= 1;
					}
					j += 1;
					k -= 1;
				}else if(now > K){
					k -= 1;
				}else{
					j += 1;
				}
			}
		}
	}

	return answer;
}
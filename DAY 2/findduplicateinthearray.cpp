#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	for(auto &i : arr){
		while(arr[i] != i){
			swap(arr[i], i);
		}
	}
	for(int i = 0; i < n; i ++){
		if(i + 1 != arr[i]){
			return arr[i];
		}
	}
	return -1;
}


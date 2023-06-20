#include <bits/stdc++.h> 

int merge(vector<int>& arr, int l, int mid, int r){
	int answer = 0;
	int i = l, j = mid + 1;

	for(i = l; i <= mid; i++){
		while(j <= r && arr[i] > 2ll*arr[j]){
			j += 1;
		}
		answer += j - (mid + 1);
	}


	vector<int> temp;
	i = l;
	j = mid + 1;
	while(i <= mid && j <= r){
		if(arr[i] <= arr[j]){
			temp.push_back(arr[i]);
			i += 1;
		}else{
			temp.push_back(arr[j]);
			j += 1;
		}
	}
	while(i <= mid){
		temp.push_back(arr[i++]);
	}

	while(j <= r){
		temp.push_back(arr[j++]);
	}
	for(int i = l; i <= r; i ++){
		arr[i] = temp[i-l];
	}


	return answer;
}

int mergeSort(vector<int>& arr, int l, int r){
	if(l >= r){
		return 0;
	}
	int mid = (l+r)/2;
	int answer = mergeSort(arr, l, mid) + mergeSort(arr, mid + 1, r);
	answer += merge(arr, l, mid, r );
	return answer;
}

int reversePairs(vector<int> &arr, int n){
	return mergeSort(arr, 0, n - 1);	
}
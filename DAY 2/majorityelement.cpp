#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int answer = INT_MIN, count = 1;

	for(int i = 0; i < n ; i++){
		int num = arr[i];
		if(num == answer){
			count += 1;
		}else{
			count -= 1;
		}
		if(count == 0){
			answer = num;
			count = 1;
		}
	}
	count = 0;
	for(int i = 0; i < n; i ++){
		if(arr[i] == answer){
			count += 1;
		}
	}

	return count > n/2?answer:-1;

	return answer;
}
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xxory = 0;
	for(int i = 0; i < n; i ++){
		xxory ^= arr[i];
		xxory ^= (i + 1);
	}

	int rsmb = ((xxory)&(-xxory));
	int x = 0, y = 0;
	for(auto i : arr){
		if((i&(rsmb))){
			x ^= i;
		}else{
			y ^= i;
		}
	}
	for(int i = 1; i <= n; i ++){
		if((i&(rsmb))){
			x ^= i;
		}else{
			y ^= i;
		}
	}
	for(int i = 0; i < n; i++){
		if(arr[i] == x){
			return(make_pair(y, x));
		}else if(arr[i] == y){
			return(make_pair(x, y));
		}
	}
	return {-1, -1};
}

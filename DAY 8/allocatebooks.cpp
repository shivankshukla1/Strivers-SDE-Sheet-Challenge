#include <bits/stdc++.h> 

bool func(vector<int>& time, int n, long long mid){
	int days = 1;
	long long int curr = 0;
	for(auto i : time){
		if(i > mid){
			return 0;
		}
		if(i + curr <= mid){
			curr += i;
		}else{
			days += 1;
			curr = i;
		}
	}
	// cout<<days<<" these are the days for "<<mid<<endl;
	return days <= n;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long l = 1, r = 1e18;
	long long answer;
	while(l <= r){
		long long int mid = (l+r)/2;
		if(func(time, n, mid)){
			// cout<<"True for "<<mid<<endl;
			r = mid - 1;
			answer = mid;
		}else{
			l = mid + 1;
		}

	}
	return l;
}
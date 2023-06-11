#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	if(m == 1 || n == 1){
		return 1;
	}
	m = n + m - 2;
	n -= 1;
	long long int answer = 1;

	for(int i = 1; i <= n; i ++){
		answer *= (m - n + i);
		answer /= i;
		// cout<<answer<<" this is the answer"<<endl;

	}
	// cout<<"returning "<<answer<<endl;
	return answer;
}
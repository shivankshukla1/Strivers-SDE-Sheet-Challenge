#include <bits/stdc++.h>

long long int modularExponentiation(int x, int n, int m) {
	if(n == 0){
		return 1;
	}	
	long long int half = (modularExponentiation(x, n/2, m))%m;
	if(n%2 == 0){
		return (half*half)%m;
	}else{
		return (((half*half)%m)*x)%m;
	}
}
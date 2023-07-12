double median(vector<int>& a, vector<int>& b) {
	int l = 0, r = a.size();
	int n = a.size(), m = b.size();
	// if(n > m){
	// 	return median(b, a);
	// }
	while(l <= r){
		int mid = (l+r)/2;
		int pat1 = (l+r)/2;
		int pat2 = (n + m + 1)/2 - pat1;
		if(pat2 > m){
			l = mid + 1;
			continue;
		}else if(pat2 < 0){
			r = mid - 1;
			continue;
		}
		int l1 = pat1 == 0?INT_MIN:a[pat1-1];
		int l2 = pat2 == 0?INT_MIN:b[pat2-1];
		int r1 = pat1 == n?INT_MAX:a[pat1];
		int r2 = pat2 == m?INT_MAX:b[pat2];
		if(l1 <= r2 && l2 <= r1){
			// cout<<pat1<<" And "<<pat2<<endl;
			// cout<<l1<<" and "<<r1<<endl;
			// cout<<l2<<" And "<<r2<<endl;
			if((n + m)%2 == 0){
				double answer = max(l1, l2) + min(r1, r2);
				answer /= 2.00;
				return answer;
			}else{
				return max(l1, l2);
			}
		}else if(l1 > r2){
			r = mid - 1;
		}else{
			l = mid +1;
		}
	}
	return 1.00;
}
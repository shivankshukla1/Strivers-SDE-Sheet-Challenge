vector<int> stringMatch(string text, string pattern) {
	vector <int> soln;  
	int n = text.size();   // text size
	int m = pattern.size();   // pattern size
	
	for(int i=0; i<n; i++) {
		if(text.substr(i,m) == pattern) {
			soln.push_back(i+1);
		}
	}
	// if(soln.empty()) {
	// 	return {-1};
	// }
	return soln;
}

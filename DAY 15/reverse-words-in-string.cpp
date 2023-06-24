string reverseString(string &str){
	vector<string> word;

	string now = "";
	for(auto i : str){
		if(i == ' '){
			if(now.size()){
				word.push_back(now);
			}
			now = "";
		}else{
			now += i;
		}
	}
	if(now.size()){
		word.push_back(now);
	}



	string answer = "";
	reverse(word.begin(), word.end());
	for(auto i : word){
		answer += i;
		answer += " ";
	}

	return answer;
}

int minCharsforPalindrome(string str) {
	int i = 0, j = str.size() - 1;
	int x = j;
	int answer = 0;
	while(i < j){
		if(str[i] == str[j]){
			i += 1;
			j -= 1;
		}else{
			answer += 1;
			i = 0;
			j = --x;
		}
	}
	return answer;
}

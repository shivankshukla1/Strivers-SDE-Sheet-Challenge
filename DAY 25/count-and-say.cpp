#include <bits/stdc++.h>

string writeAsYouSpeak(int n){
	string ans="1";
	for(int i=0;i<n-1;i++)
	{
		int count=1;
		string tmp="";
		for(int j=0;j<ans.size();j++){
			if(j+1<ans.size() && ans[j]==ans[j+1])
				count++;
			else{
				tmp+=to_string(count)+ans[j];
				count=1;
			}
		}
		ans=tmp;
	}
	return ans;
}


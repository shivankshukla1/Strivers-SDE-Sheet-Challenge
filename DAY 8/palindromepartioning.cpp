#include <bits/stdc++.h> 

bool ispalin(string& s){
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(s[l] != s[r]){
            return 0;
        }  
        l += 1;
        r -= 1;
    }
    return 1;
}

void func(int ind, string& s, vector<string>& curr, vector<vector<string>>& answer){
    if(ind == s.size()){
        answer.push_back(curr);
        return;
    }
    string now = "";
    for(int i = ind ; i < s.size(); i ++){
        now += s[i];
        if(ispalin(now)){
            curr.push_back(now);
            func(i + 1, s, curr, answer);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> answer;
    vector<string> curr;
    func(0, s, curr, answer);
    return answer;
}
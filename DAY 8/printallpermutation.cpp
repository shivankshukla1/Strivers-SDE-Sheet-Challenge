#include <bits/stdc++.h> 

void func(int ind, string& s, vector<string>& answer){
    if(ind == s.size()){
        answer.push_back(s);
        return;
    }
    for(int i = ind; i < s.size(); i ++){
            swap(s[i], s[ind]);
            func(ind + 1, s, answer);
            swap(s[i], s[ind]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> answer;
    func(0, s, answer);
    return answer;
}
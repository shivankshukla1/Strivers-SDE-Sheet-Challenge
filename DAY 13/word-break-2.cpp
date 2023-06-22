#include <bits/stdc++.h> 

void func(int ind, string& s, unordered_map<string, int>& m, string& curr, vector<string>& answer){
    if(ind == s.size()){
        answer.push_back(curr);
        return;
    }
    string now = "";
    for(int i = ind ; i < s.size(); i ++){
        now += s[i];
        if(m.find(now) != m.end()){

            string pass = curr;
            if(pass.size()){
                pass += " ";
            }
            pass += now;
            func(i + 1, s, m, pass, answer);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<string, int> m;
    for(auto i : dictionary){
        m[i] = 1;
    }
    vector<string> answer;
    string curr = "";
    func(0, s, m, curr, answer);
    return answer;

}
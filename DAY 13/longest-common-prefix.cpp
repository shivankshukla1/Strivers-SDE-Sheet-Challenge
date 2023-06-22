#include <bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    sort(arr.begin(), arr.end());
    string answer = "";
    string f = arr[0], s = arr[arr.size() - 1];
    for(int i =0 ; i < f.size(); i++){
        if(f[i] == s[i]){
            answer += f[i];
        }else{
            break;
        }
    }return answer;
}



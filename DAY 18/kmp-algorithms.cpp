#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    int n = p.size();
    for(int i =0 ; i < s.size() - 1; i ++){
        int flag = 1; 
        for(int j = 0; j < n; j ++){
            if(p[j] != s[i+j]){
                flag = 0;
                break;
            }
        }
        if(flag){
            return 1;
        }
    }
    return 0;
}
#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    int ssize=s.size(),psize=p.size();
    for(int i=0;i<ssize-psize+1;i++){
        if(s.substr(i,psize)==p){
            return true;
        }
    }
    return false;
}
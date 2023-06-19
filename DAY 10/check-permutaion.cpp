#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    unordered_map<char, int> m;
    for(auto i : str1){
        m[i] += 1;
    }
    for(auto i : str2){
        m[i] -= 1;
    }
    for(auto i : m){
        if(i.second != 0){
            return 0;
        }
    }
    return 1;
}
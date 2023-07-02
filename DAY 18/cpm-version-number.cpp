#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    vector<long long int> f, s;
    long long int curr = 0;
    for(auto i : a){
        if(i != '.'){
            curr *= 10;
            curr += (i - '0');
        }else{
            f.push_back(curr);
            curr = 0;
        }
    }
    f.push_back(curr);

    curr = 0;
    for(auto i : b){
        if(i != '.'){
            curr *= 10;
            curr += (i - '0');
        }else{
            s.push_back(curr);
            curr = 0;
        }
    }
    s.push_back(curr);
    // for(auto i : f){
    //     cout<<i<<" ";
    // }
    // for(auto i : s){
    //     cout<<i<<" ";
    // }cout<<endl;
    int maxi = max(f.size(), s.size());
    while(f.size() < maxi){
        f.push_back(0);
    }
    while(s.size() < maxi){
        s.push_back(0);
    }
    for(int i = 0; i < maxi; i++){
        if(f[i] > s[i]){
            return 1;
        }else if(f[i] < s[i]){
            return -1;
        }
    }
    return 0;

}
#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    vector<pair<double, pair<int, int>>> v;
    for(auto i : items){
        double x = (i.second*1.00)/(i.first);
        v.push_back({x, {i.second, i.first}});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    double answer = 0.0;
    
    for(auto i : v){
        if(i.second.second <= w){
            w -= i.second.second;
            answer += i.second.first;
        }else{

            answer += (i.first)*(w);
            break;
        }
    }


    return answer;
}
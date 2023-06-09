#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int>> v;
    int n = start.size();
    for(int i = 0; i < n; i ++){
        v.push_back({finish[i], start[i]});
    }
    sort(v.begin(), v.end());
    int answer = 0;
    int pre = -1;

    for(auto i : v){
        if(i.second >= pre){
            pre = i.first;
            answer += 1;
        }
    }

    return answer;
}
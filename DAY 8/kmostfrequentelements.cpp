#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int, int> m;
    for(auto i : arr){
        m[i] += 1;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto i : m){
        pq.push({i.second, i.first});
        if(pq.size() > k){
            pq.pop();
        }
    }
    vector<int> answer;
    while(pq.size()){
        answer.push_back({pq.top().second});
        pq.pop();
    }
    sort(answer.begin(), answer.end());
    return answer;
}
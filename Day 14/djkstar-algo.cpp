#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int, int>> adj[vertices];
    for(auto i : vec){
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }
    
    
    vector<int> answer(vertices, INT_MAX);
    answer[0] = 0;


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while(pq.size()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int nextnode = it.first;
            int edge = it.second;
            if(answer[nextnode] > answer[node] + edge){
                answer[nextnode] = answer[node] + edge;
                pq.push({answer[nextnode], nextnode});
            }
        }
    }


    return answer;
}

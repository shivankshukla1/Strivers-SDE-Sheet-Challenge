#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dis(n + 1, 1e9);
    dis[src] = 0;

    for(int i = 0; i < m; i ++){
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int edge = i[2];
            if(dis[u] != 1e9 && dis[v] > dis[u] + edge){
                dis[v] = dis[u] + edge;
            }   
        }
    }
    // for(auto i : dis){
    //     cout<<i<<" ";
    // }cout<<endl;
    return dis[dest];
}
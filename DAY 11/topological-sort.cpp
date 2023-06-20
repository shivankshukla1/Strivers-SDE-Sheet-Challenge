#include <bits/stdc++.h> 

void func(int node, vector<int>& vis, vector<int>& answer, vector<int> adj[]){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            func(it, vis, answer, adj);
        }
    }

    answer.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    for(auto i : edges){
        adj[i[0]].push_back(i[1]);
    }
    vector<int> vis(v, 0), answer;

    for(int i =0 ; i < v; i ++){
        if(!vis[i]){
            func(i, vis, answer, adj);
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}
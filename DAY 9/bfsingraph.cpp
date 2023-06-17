#include <bits/stdc++.h> 

void func(int node, vector<int> adj[], vector<int>& answer, vector<int>& vis){
    queue<int> q;
    q.push(node);
    vis[node] = 1;

    while(q.size()){
        int node = q.front();
        q.pop();
        answer.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
            }
        }
    }

}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    
    vector<int> vis(vertex, 0);
    vector<int> adj[vertex];
    for(auto i : edges){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }
    for(int i = 0; i < vertex; i ++){
        sort(adj[i].begin(), adj[i].end());
    }
    vector<int> answer;
    for(int i = 0; i < vertex; i++){
        if(!vis[i]){
            func(i, adj, answer, vis);
        }
    }
    return answer;
}
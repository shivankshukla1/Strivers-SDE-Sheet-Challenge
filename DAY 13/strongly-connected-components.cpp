#include <bits/stdc++.h>
void func(int node, vector<int>& vis, vector<int> adj[], vector<int>& answer){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            func(it, vis, adj, answer);
        }
    }

    answer.push_back(node);
}

void func2(int node, vector<int>& vis, vector<int> adj[], vector<int>& answer){
    vis[node] = 1;
    answer.push_back(node);

    for(auto i : adj[node]){
        if(!vis[i]){
            func2(i, vis, adj, answer);
        }
    }
}


vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    for(auto i : edges){
        adj[i[0]].push_back(i[1]);
    }   
    vector<int> topo;
    vector<int> vis(n, 0);
    for(int i =0 ; i < n; i ++){
        if(!vis[i]){
            func(i, vis, adj, topo);
        }
    }
    reverse(topo.begin(), topo.end());
    vector<int> adj2[n];
    for(auto i : edges){
        adj2[i[1]].push_back(i[0]);
    }
    vector<int> vis2(n, 0);

    vector<vector<int>> answer;

    for(auto i : topo){
        if(!vis2[i]){
            vector<int> curr;
            func2(i, vis2, adj2, curr);
            answer.push_back(curr);
        }
    }


    return answer;
}
bool func(int node, int par, vector<int> adj[], vector<int>& vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(func(it, node, adj, vis)){
                return true;
            }
        }else if(it != par){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n];
    for(auto i : edges){
        adj[i[0] - 1].push_back(i[1] - 1);
        adj[i[1] - 1].push_back(i[0] - 1);
    }
    vector<int> vis(n, 0);
    for(int i = 0; i < n; i ++){
        if(!vis[i]){
            if(func(i, -1, adj, vis)){
                return "Yes";
            }
        }
    }
    return "No";
}

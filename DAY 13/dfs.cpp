
void dfs(int node, vector<int>& vis, vector<int> adj[], vector<int>& curr){
    vis[node] = 1;
    curr.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, curr);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for(auto i : edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<vector<int>>answer;
    vector<int> vis(V, 0);

    for(int i = 0; i < V; i++){
        vector<int> curr;
        if(!vis[i]){
            dfs(i, vis, adj, curr);
            answer.push_back(curr);
        }
    }
    return answer;
}
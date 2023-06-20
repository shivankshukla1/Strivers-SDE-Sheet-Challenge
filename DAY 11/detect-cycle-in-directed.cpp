 bool dfs(int node, vector<int>& vis, vector<int>& dfsvis, vector<int> adj[]){
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(auto it : adj[node]){
            if(it == node){
              return 1;
            }
            if(!vis[it]){
                if(dfs(it, vis, dfsvis, adj)){
                    return true;
                }
            }else if(dfsvis[it]){
                return true;
            }
        }
        
        dfsvis[node] = 0;
        return false;
    }
  
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int> vis(n, 0), dfsvis(n, 0);
  vector<int> adj[n];

  for(auto i : edges){
    adj[i.first - 1].push_back(i.second - 1);
  }


  for(int i = 0; i < n; i ++){
    if(!vis[i]){
      if(dfs(i, vis, dfsvis, adj)){
        return 1;
      }
    }
  }
  return 0;
}
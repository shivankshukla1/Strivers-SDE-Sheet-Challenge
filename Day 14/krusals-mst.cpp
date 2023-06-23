#include <bits/stdc++.h> 
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	int answer = 0;
	vector<pair<int, int>> adj[n + 1];
	for(auto i : graph){
		adj[i[0]].push_back({i[1], i[2]});
		adj[i[1]].push_back({i[0], i[2]});
	}



	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 1});
	vector<int> vis(n + 1, 0);
	vis[1] = 1;
	while(pq.size()){
		
		int edge = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		// cout<<"Adding "<<edge<<" "<<node<<endl;
		if(vis[node] == 0){
			vis[node] = 1;
			answer += edge;
		}
		// cout<<"node is "<<node<<endl;
		for(auto it : adj[node]){
			if(!vis[it.first]){
				pq.push({it.second, it.first});
				
			}
		}
	}


	return answer;
}
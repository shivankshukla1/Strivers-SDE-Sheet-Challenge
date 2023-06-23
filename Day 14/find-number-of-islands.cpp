vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
vector<int> dy = {1, -1, 1, -1, 0, 1, -1, 0};

void func(int i, int j, vector<vector<int>>& vis, int** arr){
   vis[i][j] = 1;
   for(int ind = 0; ind < 8; ind++){
      int x = i + dx[ind];
      int y = j + dy[ind];
      if(x >= 0 && y >= 0 && x < vis.size() && y < vis[0].size())
      if(!vis[x][y] && arr[x][y]){
         func(x, y, vis, arr);
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<int>> vis(n, vector<int>(m, 0));
   int answer = 0;
   for(int i = 0; i < n; i ++){
      for(int j = 0; j < m; j ++){
         if(!vis[i][j] && arr[i][j]){
            answer += 1;
            func(i, j, vis, arr);
         }
      }
   }
   return answer;
}

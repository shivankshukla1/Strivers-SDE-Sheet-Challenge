#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({i, j});
            }
        }
    }

    int ans = 0;
    q.push({-1, -1});

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        if(i == -1 && j == -1 && q.size() == 1){
            q.pop();
            break;
        }
        else if(i == -1 && j == -1 && q.size() > 1){
            ans++;
            q.pop();
            q.push({-1, -1});
        }
        else{
            if(i-1 >= 0 && grid[i-1][j] == 1){
                grid[i-1][j] = 2;
                q.push({i-1, j});
            }
            if(i+1 < n && grid[i+1][j] == 1){
                grid[i+1][j] = 2;
                q.push({i+1, j});
            }
            if(j-1 >= 0 && grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                q.push({i, j-1});
            }
            if(j+1 < m && grid[i][j+1] == 1){
                grid[i][j+1] = 2;
                q.push({i, j+1});
            }
            q.pop();
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                return -1;
            }
        }
    }

    return ans;
}
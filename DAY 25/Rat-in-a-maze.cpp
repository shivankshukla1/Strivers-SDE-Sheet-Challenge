#include <bits/stdc++.h> 


void helper(vector<vector<int> > &maze, int n, vector<vector<int> > &ans, vector<int>&temp, int row, int col){

  if(row<0 || row>=n || col<0 || col>=n || maze[row][col]==0 || temp[row*n+col]==1){
    return;
  }

  if(row == n-1 && col==n-1)
  {
    temp[row*n+col] = 1;
    ans.push_back(temp);
  }
  temp[row*n+col] = 1;
  helper(maze,n,ans,temp,row,col+1);
  helper(maze,n,ans,temp,row-1,col);
  helper(maze,n,ans,temp,row,col-1);
  helper(maze,n,ans,temp,row+1,col);
  temp[row*n+col] = 0;
}


vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> ans;
  vector<int>temp(n*n,0);
  helper(maze,n,ans,temp,0,0);
  return ans;
}
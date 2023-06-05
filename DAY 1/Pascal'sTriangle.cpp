#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> answer;

    for(int i = 0; i < n; i ++){
      if(i == 0){
        answer.push_back({1});
      }else{

        vector<long long int> curr;
      
        curr.push_back(1);
      
        for(int j = 1; j < i; j ++){
          curr.push_back(answer[i-1][j] + answer[i-1][j-1]);
        }
      
        curr.push_back(1);
        answer.push_back(curr);
      
      }
    }
    return answer;
}

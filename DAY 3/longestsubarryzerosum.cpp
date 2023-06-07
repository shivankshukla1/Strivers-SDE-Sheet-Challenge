#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  int answer = 0;
  unordered_map<int, int> m;
  m[0] = -1;
  int curr = 0;
  int ind = 0;
  for(auto i : arr){
    curr += i;
    if(m.find(curr) != m.end()){
      answer = max(answer, ind - m[curr]);
    }else{
      m[curr] = ind;
    }
    ind += 1;
  }

  return answer;
}
#include <bits/stdc++.h>
int largestRectangle(vector < int > & heights) {
  int answer = 0;
  stack<int> st;
  for(int i = 0; i < heights.size(); i ++){
    while(st.size() && heights[st.top()] >= heights[i]){
      int curr = heights[st.top()];
      st.pop();
      int len;
      if(st.size()){
        len = i - st.top() - 1;
      }else{
        len = i;
      }
      // cout<<i<<" is "<<i<<endl;
      // cout<<curr<<" And "<<len<<endl;
      curr *= len;
      
      answer = max(answer, curr);
    }

    st.push(i);
  }
  while(st.size()){
      int curr = heights[st.top()];
      int len;
      st.pop();
      if(st.size() == 0){
        len = heights.size();
      }else{
        len = heights.size() - 1 - st.top();
      }
      curr *= len;
      answer = max(answer, curr);
    }


   return answer;
 }
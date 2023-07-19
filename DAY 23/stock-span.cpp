#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    vector<int> answer(price.size(), 0);
    stack<int> st;
    for(int i = 0; i < price.size(); i ++){
        while(st.size() && price[st.top()] <= price[i]){
            st.pop();
        }
        if(st.size()){
            answer[i] = i - st.top();
        }else{
            answer[i] = i + 1;
        }
        st.push(i);
    }
    return answer;
}   
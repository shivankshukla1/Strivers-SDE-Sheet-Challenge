#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {

    vector<int> answer(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i --){
        while(st.size() && st.top() <= arr[i]){
            st.pop();
        }
        
        if(st.size()){
            answer[i] = st.top();
        }else{
            answer[i] = -1;
        }

        st.push(arr[i]);
    }
    return answer;
}
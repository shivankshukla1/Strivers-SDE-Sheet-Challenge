#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> answer(n);

    stack<int> st;

    for(int i = n - 1; i >= 0; i--){
        while(st.size() && st.top() >= arr[i]){
            st.pop();
        }
        if(st.size() == 0){
            answer[i] = -1;
        }else{
            answer[i] = st.top();
        }
        st.push(arr[i]);
    }


    return answer;
}
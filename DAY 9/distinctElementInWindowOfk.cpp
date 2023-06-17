#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    unordered_map<int ,int> m;
    vector<int> answer;

    for(int i =0 ; i < arr.size(); i ++){
        m[arr[i]] += 1;
        if(i >= k){
            m[arr[i-k]] -= 1;
            if(m[arr[i-k]] == 0){
                m.erase(arr[i-k]);
            }
        }
        if(i >= k - 1){
            answer.push_back(m.size());
        }
    }

    return answer;
}

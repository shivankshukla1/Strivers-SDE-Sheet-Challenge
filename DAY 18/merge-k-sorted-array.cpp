#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i < k; i ++){
        pq.push({kArrays[i][0], {i, 0}});
    }
    vector<int> answer;
    while(pq.size()){
        int ele = pq.top().first;
        int kth = pq.top().second.first;
        int ind = pq.top().second.second;
        pq.pop();

        answer.push_back(ele);
        ind += 1;
        if(ind < kArrays[kth].size()){
            pq.push({kArrays[kth][ind], {kth, ind}});
        }

    }
    return answer;
}

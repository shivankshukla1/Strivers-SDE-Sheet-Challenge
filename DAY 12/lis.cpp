#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> v;

    for(int i = 0; i < n; i ++){
        int ind = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        if(ind < v.size()){
            v[ind] = arr[i];
        }else{
            v.push_back(arr[i]);
        }
    }

    return v.size();
}

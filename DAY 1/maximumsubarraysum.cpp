#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long answer = 0;
    long long curr = 0;
    for(int i = 0; i < n; i ++){
        curr += arr[i];
        answer = max(answer, curr);
        if(curr < 0){
            curr = 0;
        }
    }
    return answer;
}
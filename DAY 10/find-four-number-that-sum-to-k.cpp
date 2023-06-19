#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());
    for(int i =0 ; i < n - 3; i ++){
            for(int j = i + 1; j < n - 2; j++){
                    int l = j + 1, r = n - 1;
                    while(l < r){
                        long long int curr = arr[i];
                        curr += arr[j];
                        curr += arr[l];
                        curr += arr[r];
                        if(curr == target){
                            return "Yes";
                        }else if(curr > target){
                            r -= 1;
                        }else{
                            l += 1;
                        }
                    
                }
            }
    }
    return "No";
}

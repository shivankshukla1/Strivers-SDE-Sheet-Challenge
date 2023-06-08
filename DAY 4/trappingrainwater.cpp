#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long answer = 0;
    long l = 0, r = n - 1, lmax = INT_MIN, rmax = INT_MIN;

    while(l <= r){
        if(arr[l] < arr[r]){
            lmax = max(lmax, arr[l]);
            answer += lmax - arr[l];
            l += 1;
        }else{
            rmax = max(rmax, arr[r]);
            answer += rmax - arr[r];
            r -= 1;
        }
    }





    return answer;
}
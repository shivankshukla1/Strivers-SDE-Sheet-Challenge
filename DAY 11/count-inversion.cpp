#include <bits/stdc++.h>

long long merge(long long * arr, int l, int mid, int r){
    long long answer = 0;
    vector<int> temp;
    int i = l, j = mid + 1;

    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i += 1;
        }else{
            answer += mid - i + 1;
            temp.push_back(arr[j]);
            j += 1;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i += 1;
    }

    while(j <= r){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i = l; i <= r; i++){
        arr[i] = temp[i-l];
    }

    return answer;
}

long long mergeSort(long long * arr, int l, int r){
    if(l >= r){
        return 0;
    }
    int mid = (l+r)/2;
    long long answer = mergeSort(arr, l, mid) + mergeSort(arr, mid + 1, r);
    answer += merge(arr, l, mid, r);
    return answer;
}
long long getInversions(long long *arr, int n){
    long long answer = mergeSort(arr, 0, n - 1);

    return answer;
}
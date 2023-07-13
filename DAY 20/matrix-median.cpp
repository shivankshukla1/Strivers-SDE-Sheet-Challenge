#include<bits/stdc++.h>
bool func(vector<vector<int>>& mat, int curr, int req){
    int count = 0;
    
    for(int i = 0; i < mat.size(); i ++){
        count += upper_bound(mat[i].begin(), mat[i].end(), curr) - mat[i].begin();
    }



    return count >= req;
}


int getMedian(vector<vector<int>> &matrix)
{
    int l = 1, r = 1e5;
    int answer = -1;
    int n = matrix.size(), m = matrix[0].size();
    int req= (n*m)/2 + 1;
    while(l <= r){
        int mid = (l+r)/2;
        if(func(matrix, mid, req)){
            answer = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return answer;
}
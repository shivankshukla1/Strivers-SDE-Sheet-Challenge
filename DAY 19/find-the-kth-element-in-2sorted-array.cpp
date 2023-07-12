#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(m > n){
        return ninjaAndLadoos(row2, row1, n, m, k);
    }
    int l = 0, r = m;
    while(l <= r){
        int mid = (l+r)/2;
        int pat1 = mid;
        int pat2 = k - mid;
        if(pat2 < 0){
            r = mid - 1;
            continue;
        }else if(pat2 > n){
            l = mid + 1;
            continue;
        }

        int l1 = pat1 == 0?INT_MIN:row1[pat1-1];
        int l2 = pat2 == 0?INT_MIN:row2[pat2-1];
        int r1 = pat1 == m?INT_MAX:row1[pat1];
        int r2 = pat2 == n?INT_MAX:row2[pat2];
        if(l1 <= r2 && l2 <= r1){
           return max(l1, l2);
        }else if(l1 > r2){
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    return 0;

}
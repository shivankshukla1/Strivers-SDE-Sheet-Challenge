#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int f = 0, s = 0, count1 = 0, count2 = 0;
    for(auto i : arr){
        if(f == i){
            count1 += 1;
        }else if(s == i){
            count2 += 1;
        }else if(count1 == 0){
            f = i;
            count1 = 1;
        }else if(count2 == 0){
            s = i;
            count2 = 1;
        }else{
            count1 -= 1;
            count2 -= 1;
        }
    }
    vector<int> answer;
    count1 = 0;
    count2 = 0;

    for(auto i : arr){
        if(i == f){
            count1 += 1;
        }else if(i == s){
            count2 += 1;
        }
    }
    int n = arr.size();
    if(count1 > n/3){
        answer.push_back(f);
    }
    if(count2 > n/3){
        answer.push_back(s);
    }


    return answer;
}
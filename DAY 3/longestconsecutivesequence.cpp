#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_map<int, int> m;
    for(auto i : arr){
        m[i] = 1;
    }   
    int answer = 0;

    for(auto i : arr){
        int num = i;
        int curr = 0;
        if(m.find(num - 1) == m.end()){
            while(m.find(num) != m.end()){
                num += 1;
                curr += 1;
            }
        }
        answer = max(answer, curr);
    }

    return answer;
}
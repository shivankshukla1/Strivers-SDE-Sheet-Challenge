#include <bits/stdc++.h> 

bool cmp(vector<int>& a, vector<int>& b){
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);
    int answer = 0;
    vector<int> time(3001, 0);

    for(auto i : jobs){
        int flag = 0;

        for(int j = i[0]; j >= 1; j--){
            if(time[j] == 0){
                time[j] = 1;
                flag = 1;
                break;
            }
        }

        if(flag){
            answer += i[1];
        }
    }


    return answer;
}

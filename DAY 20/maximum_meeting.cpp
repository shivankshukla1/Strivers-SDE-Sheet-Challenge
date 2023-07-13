int maximumMeetings(vector<int> &start, vector<int> &end)
{
    vector<pair<int, int>> arr;
    for(int i = 0; i < start.size(); i++){
        arr.push_back({end[i], start[i]});
    }
    sort(arr.begin(), arr.end());
    int answer = 0;
    int pre = -1;
    for(auto i : arr){
        if(i.second > pre){
            pre = i.first;
            answer += 1;
        }
    }
    return answer;
}
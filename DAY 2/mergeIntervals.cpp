vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> answer;
    int size = -1;
    for(auto i : intervals){
        if(size==-1){
            size += 1;
            answer.push_back(i);
        }else if(answer[size][1] < i[0]){
            answer.push_back(i);
            size += 1;
        }else{
            answer[size][1] = max(answer[size][1], i[1]);
        }
    }
    return answer;
}

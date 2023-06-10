
void func(int ind, vector<int>& arr, int sum, vector<int>& curr, vector<vector<int>>& answer){
    
    if(ind == arr.size()){
        if(sum == 0){
            answer.push_back(curr);
            return;
        }
        return;
    }
    func(ind + 1, arr, sum, curr, answer);
    curr.push_back(arr[ind]);
    func(ind + 1, arr, sum - arr[ind], curr, answer);
    curr.pop_back();
    

}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> answer;
    vector<int> curr;
    func(0, arr, k, curr, answer);
    return answer;
}
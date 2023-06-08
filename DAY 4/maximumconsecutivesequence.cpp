int longestSubSeg(vector<int> &arr , int n, int k){
    int answer = 0;
    int l = 0, r = 0;
    while(r < arr.size()){
        if(arr[r] == 0){
            k -= 1;
        }
        while(k < 0){
            if(arr[l] == 0){
                k += 1;
            }
            l += 1;
        }
        answer = max(answer, r - l + 1);
        r += 1;
    }
    return answer;
}

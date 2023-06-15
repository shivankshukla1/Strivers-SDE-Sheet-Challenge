string kthPermutation(int n, int k) {
    int curr = 1;
    vector<int> v;
    for(int i = 1; i < n; i ++){
        curr *= i;
        v.push_back(i);
    }
    v.push_back(n);
    k -= 1;
    
    string answer = "";

    while(true){
        int ind = k/curr;
        answer += char(v[ind] + '0');
        v.erase(v.begin() + ind);
        if(v.size() == 0){
            break;
        }
        k %= curr;
        curr /= v.size();
    }

    return answer;
}

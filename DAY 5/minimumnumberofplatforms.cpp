int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    int answer = 1, curr = 1;
    int ind = 1, ind2 = 0;
    while(ind < n && ind2 < n){
        if(at[ind] > dt[ind2]){
            curr -= 1;
            ind2 += 1;
        }else{
            curr += 1;
            ind += 1;
        }
        answer = max(answer, curr);
    }

    return answer;
}
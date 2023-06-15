int func(int a, int b, int m){
  long long int answer = 1;
  for(int i = 0 ; i < b; i ++){
    answer *= a;
    if(answer > m){
      return INT_MAX;
    }
  }
  return answer;
}

int NthRoot(int n, int m) {
  int l = 1, r = m;
  while(l <= r){
    int mid = (l+r)/2;
    if(func(mid, n, m) == m){
      return mid;
    }else if(func(mid, n, m) == INT_MAX){
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  return -1;
}
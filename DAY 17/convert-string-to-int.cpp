#include <bits/stdc++.h> 
int atoi(string str) {
    int answer = 0;
    int sign = 0;
    for(auto i : str){
        if(i >= '0' && i <= '9'){
            answer*= 10;
            answer += (i - '0');
        }else if(i == '-'){
            sign += 1;    
        }
    }
    if(sign%2){
        answer *= -1;
    }
    return answer;
}
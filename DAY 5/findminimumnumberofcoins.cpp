#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int answer = 0;
    for(int ind = coins.size() - 1; ind >= 0 ; ind--){
        answer += amount/coins[ind];
        amount %= coins[ind];
    }
    return answer;
}

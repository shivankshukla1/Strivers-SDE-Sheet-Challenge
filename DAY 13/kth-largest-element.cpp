#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    Kthlargest(int k, vector<int> &arr) {
       K = k;
       for(auto i : arr){
           add(i);
       }
    }

    void add(int num) {
        pq.push(num);
        if(pq.size() > K){
            pq.pop();
        }
    }

    int getKthLargest() {
        return pq.top();
    }

};
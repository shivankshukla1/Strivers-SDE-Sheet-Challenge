#include <bits/stdc++.h>
void findMedian(int *arr, int n)
{
    priority_queue<int> front;
    priority_queue<int, vector<int>, greater<int>> back;
    for(int i = 0; i < n; i ++){
        
        front.push(arr[i]);
        back.push(front.top());
        front.pop();
        
        if(back.size() > front.size()){
            front.push(back.top());
            back.pop();
        }

        if(front.size() == back.size()){
            int curr = front.top() + back.top();
            curr /= 2;
            cout<<curr<<" "; 
        }else{
            int curr = front.top();
            // arr[i] = curr;
            cout<<curr<<" "; 
        }

    }
}
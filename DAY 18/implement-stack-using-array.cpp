#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    vector<int> st;
    int size, ind;
    Stack(int capacity) {
        size = capacity;
        st.resize(size);
        ind = 0;
    }

    void push(int num) {
        if(ind >= size){
            return;
        }else{
            st[ind] = num;
            ind += 1;
        }
    }

    int pop() {
        if(ind > 0){
            ind -= 1;
            return st[ind];
        }else{
            return -1;
        }
    }
    
    int top() {
        if(ind == 0){
            return -1;
        }else{
            return st[ind-1];
        }
    }
    
    int isEmpty() {
        return ind == 0;
    }
    
    int isFull() {
        return ind == size;
    }
    
};
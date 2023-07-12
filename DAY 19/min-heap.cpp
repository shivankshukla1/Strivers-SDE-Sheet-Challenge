#include <bits/stdc++.h> 

void heapify(vector<int>& arr, int ind, int size){
    // cout<<ind<<" this is ind"<<endl;
    int smallest = ind;
    int left = 2*ind + 1;
    int right = 2*ind + 2;
    if(left < size && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < size && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest == ind){
        return;
    }else{
        swap(arr[ind], arr[smallest]);
        heapify(arr, smallest, size);
    }
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> heap(n, 0);
    int size = 0;
    vector<int> answer;
    for(auto i : q){
        // cout<<"this is the query"<<endl;
        if(i[0] == 0){
            heap[size] = i[1];
            size += 1;
            for(int i = size/2 - 1; i >= 0; i--){
                // cout<<"ind is "<<i<<endl;
                heapify(heap, i, size);
            }
        }else{
            if(size){
                answer.push_back(heap[0]);
                swap(heap[0], heap[size-1]);
                size -= 1;
                heapify(heap, 0, size);
            }else{
                answer.push_back(-1);
            }
        }
    }  
    return answer;
}
